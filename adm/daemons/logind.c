/*  三界神话·版本 1.0 —— SanJie Myth version 1.0  */
//
// logind.c
//
// 请不要在线直接edit本文件！
// Rewritten by mudring May/10/2002
// Modify by mudring Aug/06/2002
// Optimized By Mudring Jun/13/2003

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <mudlib.h>

inherit F_DBASE;

#define NO_CHECK_WIZPWD


int wiz_lock_level = WIZ_LOCK_LEVEL;
int ppls = 0;

protected void check_ok(object ob);
protected void get_passwd(string pass, object ob);
protected void get_ad_passwd(string pass, object ob);
protected void encoding(string arg, object ob);
// protected void if_young(string arg, object ob);
protected void get_id(string arg, object ob);
protected void confirm_id(string yn, object ob);
protected void confirm_gift(object user);

object make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(object, string arg);

void create()
{
    seteuid(getuid());
    set("channel_id", "连线精灵");

    if (file_size("/log/ppls") > 0)
        sscanf(read_file("/log/ppls"), "%d", ppls);
}

int remove()
{
    write_file("/log/ppls", sprintf("%d", ppls), 1);
        return 1;
}

void logon(object ob)
{
    object *usr;
    int login_cnt = 0;
    string ip = query_ip_number(ob);

    if (++ppls % 100 == 0) remove();

    usr = filter_array(children(LOGIN_OB), (: interactive :));
    foreach (object item in usr)
        login_cnt += query_ip_number(item) == ip;
    if (login_cnt > 3)
    {
        write(HIW"请你稍候再进入本MUD...... \n");
        destruct(ob);
        return;
    }

#ifdef GB_AND_BIG5
    write(ESC "[2J");
    color_cat(BANNER);
    write(HIC"\n────────────────────────────────────\n"NOR);
    write("\n       "HIR"欢迎光临"NOR HIC + CHINESE_MUD_NAME +NOR "请您选择你所使用的内码种类(GB/BIG5)\n");
    write("          Welcome to "BLINK HIY"SanJie Myth !"NOR" Select GB or BIG5 (GB/BIG5):");
    input_to((: encoding :), ob);
#else
    encoding("gb", ob);
#endif

}

protected void encoding(string arg, object ob)
{
    object *usr;
    int i, wiz_cnt, ppl_cnt, login_cnt;
    int ctime,utime;

    ctime = this_object()->query_temp("clean_time");
    utime = uptime();
    if (utime - ctime >= 300)
    {
        this_object()->set_temp("clean_time", utime);
        this_object()->delete_temp("newid");
    }

    if (!arg || arg=="")
    {
        write("\nSelect 国标码 GB or き絏 BIG5 ("HIR"gb"NOR"/"HIY"big5"NOR"):");
        input_to( (: encoding :), ob );
        return;
    } else
    if (lower_case(arg)[0] == 'b')
        ob->set_temp("big5", 1);
    else if (lower_case(arg)[0] != 'g')
    {
        write("\nSelect 国标码 GB or き絏 BIG5 ("HIR"gb"NOR"/"HIY"big5"NOR"):");
        input_to( (: encoding :), ob );
        return;
    }

    if (__DIR__"band"->is_strict_banned(query_ip_number(ob)) == 1)
    {
        write(HIR"您的地址在本 MUD 之信誉被人破坏了。\n"NOR);
        destruct(ob);
        log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
        return;
    }

    write(ESC "[2J");
    color_cat(WELCOME);
//    write("本站总共访问人次：" HIY + chinese_number(ppls) + NOR "\n");
    "/cmds/usr/mudlist"->main(1);
    UPTIME_CMD->main(1);

    usr = users() + filter(children(LOGIN_OB), (: interactive :));
    wiz_cnt = 0;
    ppl_cnt = 0;
    login_cnt = 0;
    for(i = 0; i < sizeof(usr); i++)
    {
        if (base_name(usr[i]) == LOGIN_OB)
            login_cnt++;
        else if (wizardp(usr[i]))
        {
            if (! usr[i]->query("env/invisibility")) wiz_cnt++;
        }
        else ppl_cnt++;
    }

    printf("目前共有"HIC"%s"NOR"位管理人员、"HIC"%s"NOR"位玩家，以及"HIC"%s"NOR"位使用者在尝试连线。\n",
        chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );

    if (ob) ob->set_temp("id_count",0);

#ifndef GB_AND_BIG5
    write("[提示：如果按ENTER键后系统没有响应，请试 Ctrl-ENTER]\n\n");
#endif
    write("\n您的英文名字：（新玩家请键入 new 注册）");

#ifdef CHANGE_SITE
    if (query_ip_port(ob) == 9999)
        __DIR__"changed"->change_site(ob);
    else
#endif

    input_to( (: get_id :), ob);
}

protected void get_id(string arg, object ob)
{
    object ppl;
    int id_count;
    string ip = query_ip_number(ob);

    if(!ob) return;

    id_count=ob->query_temp("id_count");
    id_count++;
    ob->set_temp("id_count",id_count);
    if (id_count>6)
    {
        destruct(ob);
        return;
    }

    arg = lower_case(arg);
    if (!check_legal_id(arg))
    {
        write("您的英文名字：");
        input_to("get_id", ob);
        return;
    }

    if (!__DIR__"sited"->is_valid(arg, ip))
    {
        log_file("SITE", sprintf("%-9s从 %-16s被拒绝(%s)\n", arg, ip, ctime(time())));
        write("对不起，你不能从当前地址登录这个人物。\n");
        write("\n您的英文名字：（新玩家请键入 new 注册）");
        input_to((: get_id :), ob);
        return;
    }

    if (ob->set("id", arg) != arg )
    {
        write("Failed setting user name.\n");
        destruct(ob);
        return;
    }

#ifdef MAX_USERS
    if (!wiz_level(arg)
        && sizeof(users()) >= MAX_USERS)
    {
        ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
        if (!ppl)
        {
            write("对不起，目前" + MUD_NAME + "的玩家已经太多了，请待会再来。\n");
            destruct(ob);
            return;
        }
    }

    if (!ppl && __DIR__"sited"->is_multi(arg, ip))
    {
        destruct(ob);
        return;
    }
#endif

    if (wiz_level(arg) < wiz_lock_level )
    {
        write("对不起，" + MUD_NAME + "目前处于系统维护之中。\n");
        write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
            + " 以上的人才能连线。\n");
        destruct(ob);
        return;
    }

    if (arg == "guest")
    {
        // If guest, let them create the character.
        ob->set("password", "SanJie");
        write("您的中文名字：");
        input_to("get_name", ob);
        return;
    } else
    if (arg=="new")
    { // new player login
        write("\n请您给自己取一个英文名字：");
        input_to("get_new_id",ob);
        return;
    } else
    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
    {
        if (ob->restore())
        {
            write("请输入相应密码：");
            input_to("get_passwd", 1, ob);
            return;
        }
        write("您的人物储存档出了一些问题，请利用 guest 人物通知巫师处理。\n");
        destruct(ob);
        return;
    }

    write("没有这个玩家．．．\n");
    write("您的英文名字：（新玩家请键入 new 注册）");
    input_to("get_id", ob);
    return;
}

protected void get_new_id(string arg, object ob)
{
    object ppl;
    int id_count;
    string ip = query_ip_number(ob);

    if(!ob) return;

    id_count=ob->query_temp("id_count");
    id_count++;
    ob->set_temp("id_count",id_count);
    if (id_count > 6)
    {
        destruct(ob);
        log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
        return;
    }

    if (!arg)
    {
        write("\n请您给自己取一个英文名字：");
        input_to("get_new_id", ob);
        return;
    }

    arg = lower_case(arg);
    if (!check_legal_id(arg))
    {
        write("\n请您给自己取一个英文名字：");
        input_to("get_new_id", ob);
        return;
    }

    if (ob->set("id", arg) != arg )
    {
        write("Failed setting user name.\n");
        destruct(ob);
        return;
    }

    if (!__DIR__"sited"->is_valid(arg, ip))
    {
        log_file("SITE", sprintf("%-9s从 %-16s被拒绝(%s)\n", arg, ip, ctime(time())));
        write("对不起，你不能从当前地址创造这个人物。\n");
        write("\n请您给自己取一个英文名字：");
        input_to("get_new_id",ob);
        return;
    }

    ppl = find_body(arg);
    if(ppl || arg=="guest" || arg=="new") {
        write("这个名字已经被别的玩家使用了．．．");
        write("\n请您给自己取一个英文名字：");
        input_to("get_new_id",ob);
        return;
    }

    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
        write("这个名字已经被别的玩家使用了．．．");
        write("\n请您给自己取一个英文名字：");
        input_to("get_new_id",ob);
        return;
    }

    confirm_id("Yes", ob);
    return;
}

protected void get_passwd(string pass, object ob)
{
    string ad_pass;
    string my_pass, id;

    my_pass = ob->query("password");
    ad_pass = ob->query("ad_password");
    if (! stringp(my_pass)
		|| crypt(pass, my_pass) != my_pass )
    {
        if (! stringp(ad_pass)
			|| crypt(pass, ad_pass) != ad_pass )
        {
            write("密码错误！\n");
            if((id=ob->query("id")) && member_array(id,SECURITY_D->get_wizlist())!=-1)
                log_file("wizlogin",ctime(time())+" "+id+
                    " failed login from "+query_ip_number(ob)+"\n");
            destruct(ob);
            return;
        }
        write(HIR "\n你采用了管理密码进入游戏，"
              "因此请你先修改你的普通密码。\n" NOR);

        // 做标记：表示目前流程是修改密码分支。
        ob->set_temp("reset_password", 1);
        write("\n请重新设定您的普通密码：");
        input_to("new_password", 1, ob);
        return;
    }

    if (! stringp(ad_pass))
    {
         write(HIC "\n请注意：你的ID目前还没有管理密码，请设置你的管理密码。\n\n" NOR);
        write(HIG "在你普通密码丢失的情况下，你可以输入管理密码进入，并修改普通\n"
              "密码，所以请你设置一个可靠的并且与普通密码不同的管理密码，用\n"
              "来保护你的ID。平时请使用普通密码登陆，避免过于频繁的使用管理\n"
              "密码以导致潜在的泄漏风险。\n\n" NOR);
        write("请输入你的管理密码：");
        input_to("reset_ad_password", 1, ob);
        return;
    }

    // Check wizpass By Mudring...
    if ((id = ob->query("id")) && wiz_level(id) > 0)
    {
        write(HIR"№"WHT"『"HIG"请输入相应的WIZ密码"WHT"』"NOR"");
#ifdef NO_CHECK_WIZPWD
        write(HIR"\n如果你还没有设定巫师密码，请输入回车继续"NOR"");
#endif
        input_to("get_wizpwd", 1, ob);
    }
    else
        check_ok(ob);
}

protected void reset_ad_password(string pass, object ob)
{
    string my_pass;
    write("\n");

    if (strlen(pass) < 5)
    {
        write("管理密码的长度至少要五个字元，请重设您的管理密码：");
        input_to("reset_ad_password", 1, ob);
        return;
    }
    my_pass = ob->query("password");
    if (stringp(my_pass) && crypt(pass, my_pass) == my_pass)
    {
        write(HIR "为了安全起见，系统要求管理密码的密码和普通密码不能相同。\n\n" NOR);
        write("请重新输入你的管理密码：");
        input_to("reset_ad_password", 1, ob);
        return;
    }

    ob->set_temp("ad_password", crypt(pass, 0));
    write("请再输入一次您的管理密码，以确认您没记错：");
    input_to("confirm_reset_ad_password", 1, ob);
}

protected void confirm_reset_ad_password(string pass, object ob)
{
    string old_pass, id;

    write("\n");
    old_pass = ob->query_temp("ad_password");
    if (crypt(pass, old_pass) != old_pass)
    {
        write("您两次输入的管理密码并不一样，请重新设定一次管理密码：");
        input_to("reset_ad_password", 1, ob);
        return;
    }

    ob->set("ad_password", old_pass);
    // Check wizpass By Mudring...
    if ((id = ob->query("id")) && wiz_level(id) > 0)
    {
        write(HIR"№"WHT"『"HIG"请输入相应的WIZ密码"WHT"』"NOR"");
        input_to("get_wizpwd", 1, ob);
    }
    else
        check_ok(ob);

}
protected void check_ok(object ob)
{
    object user;

    // Check if we are already playing.
    user = find_body(ob->query("id"));

    if (user)
    {
        // Check last connect By Mudring...
        if ( user->query("last_relogin") < time() &&
            user->query("last_relogin") > time() - 30 &&
            ! wiz_level(user))
        {
            write("你距上一次重新连线时间只有" + chinese_number(time() - user->query("last_relogin")) +
                "秒钟，请稍候再登录。\n");
            user->set("last_relogin", time());
            destruct(ob);
            return;
        }
        if (user->is_net_dead())
        {
            reconnect(ob, user);
            return;
        }
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }

    if (objectp(user = make_body(ob)))
    {
        if (user->restore())
        {
            mixed err;
            string msg;

            log_file("usage", sprintf("%s(%s) loggined from %s (%s)\n",
                 user->query("name"), user->query("id"),
                 query_ip_number(ob), ctime(time()) ) );

            if (ob->query("kickout_time") < time() &&
                ob->query("kickout_time") > time() - 300 &&
                ! wiz_level(user))
            {
                write(HIG"对不起，你刚刚才被踢出游戏，还是待会儿再尝试连线吧。\n"NOR);
                destruct(ob);
                destruct(user);
                return;
            }
            if (ob->query("last_on") < time() &&
                ob->query("last_on") > time() - 60 &&
                ! wiz_level(user))
            {
                write("你距上一次退出时间只有" + chinese_number(time() - ob->query("last_on")) +
                      "秒钟，请稍候再登录。\n");
                destruct(user);
                destruct(ob);
                return;
            }

            user->set("last_save", time());
            if (err = catch(enter_world(ob, user)))
            {
                user->set_temp("error", err);
                msg = HIR "\n你无法进入这个世界，可能你的档"
                      "案出了一些问题，需要和巫师联系。\n\n" NOR;
                if (mapp(err))
                    msg += MASTER_OB->standard_trace(err, 1);
                user->set_temp("error_message", msg);
                tell_object(user, msg);
            }
            return;
        } else
        {
            destruct(user);
            write(HIR "\n无法读取你的数据档案，您需要和巫师联系。\n" NOR);
            write(WHT "你可以选择重新创造玩家(y/n)：" NOR);
            input_to("create_new_player", ob);
         }
    } else
    write(HIR "无法创建该玩家，你可以尝试重新登录或是和巫师联系。\n" NOR);
}

protected void get_wizpwd(string pass, object user,object ob)
{
    string old_pass;
    object userp;
    write("\n");
    old_pass = user->query("wiz_password");
    userp = find_body(user->query("id"));

    if (!user->query("wiz_password"))
    {
#ifdef NO_CHECK_WIZPWD
        write("请登陆后用wizpwd来设定你的巫师密码！\n");
        check_ok(user);
#else
        write("你没有设定WIZ密码，请联系系统管理员！\n");
        destruct(userp);
        destruct(user);
        destruct(ob);
#endif
        return;
    }

    if (user->query("wiz_password"))
    {
        if (crypt(pass, old_pass)==old_pass
			)
        {
            write("密码正确！\n");
            check_ok(user);
            return;
        }
        else
        {
            write("密码错误！\n");
            destruct(userp);
            destruct(user);
            destruct(ob);
            return;
        }
    }
}

protected void create_new_player(string yn, object ob)
{
    if (yn != "y" && yn != "Y")
    {
        write("\n那好吧，本次连接登录失败了。");
        destruct(ob);
        return;
    }

    write(HIW "\n现在开始重新创造 " HIY + ob->query("id") +
          HIW " 这个玩家。\n" NOR);
    confirm_id(yn, ob);
}

protected void confirm_relogin(string yn, object ob, object user)
{
    object old_link;

    if (! yn || yn=="")
    {
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }

    if (yn[0]!='y' && yn[0]!='Y')
    {
        write("好吧，欢迎下次再来。\n");
        destruct(ob);
        return;
    }

    if (user)
    {
        tell_object(user, "有人从别处( " + query_ip_number(ob)
                + " )连线取代你所控制的人物。\n");
        log_file("usage", sprintf("%s(%s) replaced by %s (%s)\n",
             user->query("name"), user->query("id"),
             query_ip_number(ob), ctime(time())));

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if (old_link)
        {
            if (interactive(user))
            {
                old_link->set("last_on", time());
                old_link->set("last_from", query_ip_name(user) + "(" + query_ip_number(user) + ")");
                old_link->save();
                ob->restore();
                exec(old_link, user);
            }
            destruct(old_link);
        }
    } else
    {
        write("在线玩家断开了连接，你需要重新登陆。\n");
        destruct(ob);
        return;
    }

    reconnect(ob, user);
}

protected void confirm_id(string yn, object ob)
{
    if (this_object()->query_temp("newid/"+ob->query("id"))){
        write("已经有人在注册这个id了。\n");
        destruct(ob);
        return;
    }
    this_object()->set_temp("newid/"+ob->query("id"),1);

write(HIW
    "\n为了保证你的人物的安全，游戏要求你设置两个密码。一个是管理密\n"
    "码，这个密码可以在你遗失了普通密码时登录游戏，并用来修改普通\n"
    "密码。平时请使用普通密码登陆，避免过于频繁的使用管理密码以导\n"
    "致潜在的泄漏风险。\n\n"
NOR);
    write("请设定您的管理密码：");
    input_to("new_ad_password", 1, ob);
}

protected void new_ad_password(string pass, object ob)
{
    write("\n");
    if (strlen(pass) < 5)
    {
        write("管理密码的长度至少要五个字元，请重设您的管理密码：");
        input_to("new_ad_password", 1, ob);
        return;
    }
    ob->set_temp("ad_password", crypt(pass, 0));
    write("请再输入一次您的管理密码，以确认您没记错：");
    input_to("confirm_ad_password", 1, ob);
}
protected void confirm_ad_password(string pass, object ob)
{
    string old_pass;

    write("\n");
    old_pass = ob->query_temp("ad_password");
    if (crypt(pass, old_pass) != old_pass)
    {
        write("您两次输入的管理密码并不一样，请重新设定一次管理密码：");
        input_to("new_ad_password", 1, ob);
        return;
    }

    ob->set("ad_password", old_pass);
    write(HIM "普通密码是你平时登录游戏时使用的，游戏中可以通过 PASSWD 命令\n"
          "来修改这个密码。\n\n" NOR);
    write("请输入你的普通密码：");
    input_to("new_password", 1, ob);
}
protected void new_password(string pass, object ob)
{
    string ad_pass;

    write("\n");
    if (strlen(pass) < 5 ) {
        write("密码至少要由五个字符组成，请重设您的密码：");
        input_to("new_password", 1, ob);
        return;
    }
    if (stringp(ad_pass = ob->query("ad_password")) &&
        crypt(pass, ad_pass) == ad_pass)
    {
     write(HIR "请注意，为了安全起见，系统要求你的管理密码和普通密码不能相同。\n\n" NOR);
        write("请重新设置您的普通密码：");
        input_to("new_password", 1, ob);
        return;
    }
      ob->set_temp("password", crypt(pass, 0));
    write("请再输入一次您的密码，以确认您没记错：");
    input_to("confirm_password", 1, ob);
}

protected void confirm_password(string pass, object ob)
{
    string id, old_pass;

    write("\n");
    old_pass = ob->query_temp("password");
    if( crypt(pass, old_pass)!=old_pass ) {
        write("您两次输入的密码并不一样，请重新设定一次密码：");
        input_to("new_password", 1, ob);
        return;
    }
    ob->set("password", old_pass);
    if (ob->query_temp("reset_password"))
    {
        // 这是用户修改自己的密码分支流程，不是创建
        // 用户分支，因此转移到 check_ok 函数继续执
        // 行。
        ob->save();
        // Check wizpass By Mudring...
        if ((id = ob->query("id")) && wiz_level(id) > 0)
        {
            write(HIR"№"WHT"『"HIG"请输入相应的WIZ密码"WHT"』"NOR"");
            input_to("get_wizpwd", 1, ob);
        }
        else
            check_ok(ob);
        return;
    }
write( @TEXT

请您给自己想一个符合三界神话世界的中文名字。这个名字将
代表你在三界神话中的人物，而且往后将不能再更改。请不要
取一些不雅或是容易造成他人困扰的名字。

TEXT
);
    write("您的中文名字：");
    ob->set_temp("get_name",0);
    input_to("get_name", ob);
}

protected void get_name(string arg, object ob)
{
    string result;
    if (!check_legal_name(ob, arg))
    {
        write("您的中文名字：");
        input_to("get_name", ob);
        return;
    }
    if ( stringp(result = NAME_D->invalid_new_name(arg)) )
    {
        write("对不起，" + result);
        write("\n请重新输入您的" HIG "中文名字" NOR "：");
        input_to("get_name", ob);
        return;
    }
    ob->set("name", arg);
    printf("%O\n", ob);
    write("您的电子邮件地址（请详细填写并记住，本游戏以email来认证身份）");
    input_to("get_email",  ob);
}

protected void get_email(string email, object ob)
{
    write("\n");

    if (strsrch(email, "@") == -1 || strsrch(email, ".")==-1 || strlen(email)<9) {
        write("电子邮件地址需要是 id@address的格式。\n");
        write("您的电子邮件地址：");
        input_to("get_email", ob);
        return;
    }
    ob->set("email", email);

    write("您要扮演角色的类型？\n"
          "[" HIC "1" NOR ". 刀剑侠  "
          HIC "2" NOR ". 魔法师  "
          HIC "3" NOR ". 终结者  "
          HIC "4" NOR ". 精灵族  "
          HIC "5" NOR ". 均衡型  "
          HIC "6" NOR ". 暗黑地狱使者] ("
          HIC "1" NOR "-" HIC "6" NOR ")");
    input_to("get_type", ob);
}

protected void get_type(string type, object ob)
{
    int n;
    if (type == "")
        n = 6;
    else
        sscanf(type, "%d", n);

    if (n < 1 || n > 6)
    {
        write ("对不起，您只能选择1-6，按下回车直接选择暗黑地狱使者。\n\n");
        write("您要扮演角色的类型？(6)");
        input_to("get_type", ob);
        return;
    }

    switch(n)
    {
    case 1:
        ob->set_temp("type", "刀剑侠");
        break;
    case 2:
        ob->set_temp("type", "魔法师");
        break;
    case 3:
        ob->set_temp("type", "终结者");
        break;
    case 4:
        ob->set_temp("type", "精灵族");
        break;
    case 5:
        ob->set_temp("type", "野蛮人");
        break;
    case 6:
        ob->set_temp("type", "暗黑地狱使者");
        break;
    }

    write("您选择了" HIC + ob->query_temp("type") + NOR "的角色。\n");

    write("\n您要扮演男性(m)的角色或女性(f)的角色？");
    input_to("get_gender", ob);
}

protected void get_gender(string gender, object ob)
{
    object user;

    write("\n");
    if (gender=="")
    {
        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender", ob);
        return;
    }

    if (gender[0]=='m' || gender[0]=='M')
        ob->set_temp("gender", "男性");
    else if (gender[0]=='f' || gender[0]=='F')
        ob->set_temp("gender", "女性" );
    else
    {
        write("对不起，您只能选择男性(m)或女性(f)的角色：");
        input_to("get_gender", ob);
        return;
    }

    if (find_body(ob->query("id")))
    {
        write(HIR "这个玩家现在已经登录到这个世界上了，请"
              "退出重新连接。\n" NOR);
        destruct(ob);
        return;
    }

    ob->set("body", USER_OB);
    if (! objectp(user = make_body(ob)))
    {
        write(HIR "\n你无法登录这个新的人物，请重新选择。\n" NOR);
        destruct(ob);
        return;
    }

    user->set("hell_type", ob->query_temp("type"));
    user->set("gender", ob->query_temp("gender"));
    ob->set("registered", 0);
    user->set("registered", 0);
    log_file("newid", sprintf("%s(%s) was created from %s (%s)\n",
                    user->query("name"), user->query("id"),
                    query_ip_number(ob), ctime(time())));
    ob->set("last_from", query_ip_name(user) + "(" + query_ip_number(user) + ")");
    ob->set("last_on",time());

    confirm_gift(user);
    enter_world(ob, user);
    write("\n");
}

object make_body(object ob)
{
    string err;
    object user;

    if (! is_root(previous_object()))
    {
        log_file("static/security",
             sprintf("%s try to create player(%s) on %s.\n",
                 (string)geteuid(previous_object()),
                 (string)ob->query("id"),
                 ctime(time())));
        write("你没有权限创建玩家。\n");
        return 0;
    }
    seteuid(getuid());
    user = new(USER_OB);

    if(!user)
    {
        write("现在可能有人正在修改玩家物件的程式，无法进行复制。\n");
        write(err+"\n");
        return 0;
    }
    seteuid(ob->query("id"));
    export_uid(user);
    export_uid(ob);
    seteuid(getuid());
    user->set("id", ob->query("id"));
    user->set_name(ob->query("name"), ({ ob->query("id")}));

    return user;
}

protected void confirm_gift(object user)
{
    user->set("kar", 20 );
    user->set("str", 20 );
    user->set("cps", 20 );
    user->set("int", 25 );
    user->set("cor", 20 );
    user->set("con", 20 );
    user->set("spi", 25 );
    user->set("per", 20 );

    user->set("no_gift",1);
    CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
    user->set("title", "三界平民");
    user->set("birthday", time() );
    user->set("potential", 99);
    user->set("scorepoint",0);
    user->set("level",1);
    user->set("food", user->max_food_capacity());
    user->set("water", user->max_water_capacity());
    user->set("channels", ({ "chat","rumor","job","sldh","mete","sj", "sos" }));

    // 记录名字
    NAME_D->map_name(user->query("name"), user->query("id"));
}

varargs void enter_world(object ob, object user, int silent)
{
    int nCount;
    string startroom;
    string ip_number;
    string ip_from;
        ////////////
	// Add for 上线通知 By Aeddy 2004-1-5
       int qqnum;
       string *qqfriends;
       object qqob;
       ////////////////

    if (!is_root(previous_object()))
        return;

    reset_eval_cost();
    ob->set_temp("body_ob", user);
    user->set_temp("link_ob", ob);
    user->set_temp("big5", ob->query_temp("big5"));
    ob->set_temp("last_from", query_ip_name(ob)+"("+query_ip_number(ob)+")");

    exec(user, ob);
    user->setup();
    user->save();
    ob->save();

    ip_number = query_ip_number(user);
    if (!silent)
    {
        if (file_size(MOTD) > 0)
            user->start_more( color_filter( read_file(MOTD)) );
        nCount = ob->query("nCount");
        ob->set("nCount", ++nCount);

write(CYN"     ≡≡≡≡≡≡≡≡≡≡≡≡"HIR+MUD_NAME+"连线信息"NOR CYN"≡≡≡≡≡≡≡≡≡≡≡≡≡\n");
write(HIY"     ★  您的系统权限目前是："HIC + wizhood(user) + "\n"NOR);
write(HIY"     ★  您上次连线的地址是："HIC + ob->query("last_from") + "\n"NOR);
write(HIY"     ★  您上次连线的时间是："HIC + ctime(ob->query("last_on"))+ "\n"NOR);
write(HIY"     ★  您本次连线的时间是："HIC + ctime(time()) + "\n"NOR);
write(HIY"     ★  您是第 "HIR+chinese_number(nCount)+NOR HIY" 次连接"+CHINESE_MUD_NAME+"。\n");
write(NOR CYN"     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n\n"NOR);

        if (file_size("/etc/notice") > 0)
        {
            write(HIC"     ≡≡≡≡≡≡≡≡≡≡≡≡ "HIR"连线通知"NOR HIC" ≡≡≡≡≡≡≡≡≡≡≡≡\n");
            write(NOR"     " + color_filter(read_file("/etc/notice")));
            write(HIC"     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR);
        }

        user->set_temp("last_damage_from", "莫名其妙地");
        user->set_temp("logon_mudage", user->query("mud_age"));

        if (user->query("no_gift"))
        {
            user->move("/d/wiz/init",1);
        } else
        {
            write("请按回车继续......\n");
            input_to("nothing", user);

            if (!stringp(startroom = user->query("startroom")))
                startroom = START_ROOM;
            if (startroom[0..2] != "/d/")
                startroom = START_ROOM;
            if (user->is_ghost())
                startroom = DEATH_ROOM;
            if ((__DIR__"band"->create_char_banned(ip_number) == 1 ||
                __DIR__"band"->is_banned(ip_number)== 1) && !wizardp(user))
                startroom = GUEST_ROOM;
            if (wizardp(user))
                startroom = WIZARD_ROOM;

            if (catch(load_object(startroom)))
            {
                write("您上次退出的地方已经消失了。\n");
                startroom = START_ROOM;
            }

            user->move(startroom);
            user->set("startroom", startroom);

            tell_room(startroom, user->query("name") +
                      "连线进入这个世界。\n", ({user}));
        }

        ip_from = __DIR__"sited"->seek_ip_address(ip_number);
        CHANNEL_D->do_channel(this_object(), "sys",
            sprintf(NOR WHT "%s由 " HIG "%s" NOR WHT "连线进入,IP来自："HIG"%s"NOR,
                    user->name() + "(" + capitalize(user->query("id")) + ")",
                    ip_number, ip_from));

        NEWS_D->prompt_user(user);
        __DIR__"maild"->check_mail(user);
    }

    if (//wizhood(user) != "(admin)" &&
        EXAMINE_D->query("log_by/" + user->query("id")))
        user->start_log();

    user->set_temp("logon_time", time());
    user->set_temp("logon_exp", user->query("combat_exp"));
    user->set_temp("logon_daoxing", user->query("daoxing"));

    UPDATE_D->check_user(user, 0);
     //////////////////////////////////////////////////////
     // Add for QQ上线通知 By Aeddy 2004-1-5
	if(mapp(user->query("qq"))
	   && sizeof(user->query("qq"))!=0
	   &&!user->query("env/invisibility")) {
	qqfriends = keys(user->query("qq"));
	 for(qqnum=0;qqnum<sizeof(qqfriends);qqnum++)
                {
				qqob=find_player(qqfriends[qqnum]);
				tell_object(qqob,BLINK HIG+"三界信使通知您：你的好友"+user->query("name")+"["+capitalize(user->query("id"))+"]上线了！！\n"+NOR);
		}
         }
     ////////////////////////////////////////////////////////

    if(wizardp(user))
    {
        if (!ob->query("wiz_password"))
            write(HIR+BLINK"请用WIZPWD设定相应的WIZ密码！\n"NOR);
        CHANNEL_D->do_channel( this_object(), "wiz",
            sprintf(NOR "%s" HIY " 从 " HIG "%s" HIY " 进入连线。",
                    user->short(1), ip_number));
    } else
    {

        object caishen;
        if (objectp(caishen=find_object("/d/wiz/npc/caishen")))
            caishen->check_one(user);
        if ((user->query("kee") < 0 || user->query("sen") < 0) && living(user))
            user->unconcious();
        EXAMINE_D->examine_player(user);
    }

}

varargs void reconnect(object ob, object user, int silent)
{
    object old_link;

    old_link = user->query_temp("link_ob");

    if (old_link && old_link!=ob)
        destruct(old_link);

    user->set_temp("link_ob", ob);
    ob->set_temp("body_ob", user);
    user->set_temp("big5", ob->query_temp("big5"));
    ob->set_temp("last_from", query_ip_name(ob) + "(" + query_ip_number(ob) + ")");

    exec(user, ob);

    user->reconnect();

    if (!silent && (! wizardp(user) || !user->query("env/invisibility")))
        tell_room(environment(user), user->query("name") + "重新连线回到这个世界。Good Luck!\n",({user}));
    CHANNEL_D->do_channel(this_object(), wiz_level(user)?"wiz":"sys",
        sprintf("%s由%s重新连线进入。", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_number(user)));
    user->set("last_relogin", time());
    UPDATE_D->check_user(user, 1);
}

int check_legal_id(string id)
{
    int i;
    string *legalid;

    i = strlen(id);

    if (i < 3 || i > 8 )
    {
        write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
        return 0;
    }
    while(i--)
        if( id[i]<'a' || id[i]>'z' )
        {
            write("对不起，你的英文名字只能用英文字母。\n");
            return 0;
        }
    legalid = explode(read_file(BANNED_ID), "\n");
    for (i=0; i<sizeof(legalid); i++)
    {
        if ( id == legalid[i] )
        {
            write("对不起，这种名字会造成其他人的困扰。\n");
            return 0;
        }
    }
    return 1;
}

int check_legal_name(object ob, string name)
{
    int i;

    i = strlen(name);

    if (i < 2 || i > 12 || i%2)
    {
        write("对不起，你的中文名字必须是一到六个中文字。\n");
        return 0;
    }
    while(i--)
    {
        if( i%2==0 && !is_chinese(name[i..<0]) )
        {
            write("对不起，请您用「中文」取名字。\n");
            return 0;
        }
    }

    return 1;
}

object find_body(string name)
{
    return find_player(name);
}

int set_wizlock(int level)
{
    if( wiz_level(this_player(1)) <= level )
        return 0;
    if( geteuid(previous_object()) != ROOT_UID )
        return 0;
    wiz_lock_level = level;
    return 1;
}
