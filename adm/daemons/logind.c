/*  �����񻰡��汾 1.0 ���� SanJie Myth version 1.0  */ 
//
// logind.c
//
// �벻Ҫ����ֱ��edit���ļ���
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
    set("channel_id", "���߾���");

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
        write(HIW"�����Ժ��ٽ��뱾MUD...... \n");
        destruct(ob);
        return;
    }

#ifdef GB_AND_BIG5
    write(ESC "[2J");
    color_cat(BANNER);
    write(HIC"\n������������������������������������������������������������������������\n"NOR);
    write("\n       "HIR"��ӭ����"NOR HIC + CHINESE_MUD_NAME +NOR"����ѡ������ʹ�õ���������(GB/BIG5)\n");
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
        write("\nSelect ������ GB or �j���X BIG5 ("HIR"gb"NOR"/"HIY"big5"NOR"):");
        input_to( (: encoding :), ob );
        return;
    } else
    if (lower_case(arg)[0] == 'b')
        ob->set_temp("big5", 1);
    else if (lower_case(arg)[0] != 'g')
    {
        write("\nSelect ������ GB or �j���X BIG5 ("HIR"gb"NOR"/"HIY"big5"NOR"):");
        input_to( (: encoding :), ob );
        return;
    }
    
    if (__DIR__"band"->is_strict_banned(query_ip_number(ob)) == 1)
    {
        write(HIR"���ĵ�ַ�ڱ� MUD ֮���������ƻ��ˡ�\n"NOR);
        destruct(ob);
        log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
        return;
    }
 
    write(ESC "[2J");
    color_cat(WELCOME);
//    write("��վ�ܹ������˴Σ�" HIY + chinese_number(ppls) + NOR "\n");
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

    printf("Ŀǰ����"HIC"%s"NOR"λ������Ա��"HIC"%s"NOR"λ��ң��Լ�"HIC"%s"NOR"λʹ�����ڳ������ߡ�\n",
        chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );

    if (ob) ob->set_temp("id_count",0);

#ifndef GB_AND_BIG5
    write("[��ʾ�������ENTER����ϵͳû����Ӧ������ Ctrl-ENTER]\n\n");
#endif
    write("\n����Ӣ�����֣������������� new ע�ᣩ");

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
        write("����Ӣ�����֣�");
        input_to("get_id", ob);
        return;
    }

    if (!__DIR__"sited"->is_valid(arg, ip))
    {
        log_file("SITE", sprintf("%-9s�� %-16s���ܾ�(%s)\n", arg, ip, ctime(time())));
        write("�Բ����㲻�ܴӵ�ǰ��ַ��¼������\n");
        write("\n����Ӣ�����֣������������� new ע�ᣩ");
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
            write("�Բ���Ŀǰ" + MUD_NAME + "������Ѿ�̫���ˣ������������\n");
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
        write("�Բ���" + MUD_NAME + "Ŀǰ����ϵͳά��֮�С�\n");
        write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
            + " ���ϵ��˲������ߡ�\n");
        destruct(ob);
        return;
    }

    if (arg == "guest")
    {
        // If guest, let them create the character.
        ob->set("password", "SanJie");
        write("�����������֣�");
        input_to("get_name", ob);
        return;
    } else
    if (arg=="new")
    { // new player login
        write("\n�������Լ�ȡһ��Ӣ�����֣�");
        input_to("get_new_id",ob);
        return;
    } else
    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
    {
        if (ob->restore())
        {
            write("��������Ӧ���룺");
            input_to("get_passwd", 1, ob);
            return;
        }
        write("�������ﴢ�浵����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
        destruct(ob);
        return;
    } 
  
    write("û�������ң�����\n");
    write("����Ӣ�����֣������������� new ע�ᣩ");
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
        write("\n�������Լ�ȡһ��Ӣ�����֣�");
        input_to("get_new_id", ob);
        return;
    }

    arg = lower_case(arg);
    if (!check_legal_id(arg))
    {
        write("\n�������Լ�ȡһ��Ӣ�����֣�");
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
        log_file("SITE", sprintf("%-9s�� %-16s���ܾ�(%s)\n", arg, ip, ctime(time())));
        write("�Բ����㲻�ܴӵ�ǰ��ַ����������\n");
        write("\n�������Լ�ȡһ��Ӣ�����֣�");
        input_to("get_new_id",ob);
        return;
    }

    ppl = find_body(arg);
    if(ppl || arg=="guest" || arg=="new") {
        write("��������Ѿ���������ʹ���ˣ�����");
        write("\n�������Լ�ȡһ��Ӣ�����֣�");
        input_to("get_new_id",ob);
        return;
    }

    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
        write("��������Ѿ���������ʹ���ˣ�����");
        write("\n�������Լ�ȡһ��Ӣ�����֣�");
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
            write("�������\n");
            if((id=ob->query("id")) && member_array(id,SECURITY_D->get_wizlist())!=-1)
                log_file("wizlogin",ctime(time())+" "+id+
                    " failed login from "+query_ip_number(ob)+"\n");
            destruct(ob);
            return;
        }
        write(HIR "\n������˹������������Ϸ��"
              "����������޸������ͨ���롣\n" NOR);

        // ����ǣ���ʾĿǰ�������޸������֧��
        ob->set_temp("reset_password", 1);
        write("\n�������趨������ͨ���룺");
        input_to("new_password", 1, ob);
        return;
    }

    if (! stringp(ad_pass)) 
    {
         write(HIC "\n��ע�⣺���IDĿǰ��û�й������룬��������Ĺ������롣\n\n" NOR);
        write(HIG "������ͨ���붪ʧ������£�������������������룬���޸���ͨ\n"
              "���룬������������һ���ɿ��Ĳ�������ͨ���벻ͬ�Ĺ������룬��\n"
              "���������ID��ƽʱ��ʹ����ͨ�����½���������Ƶ����ʹ�ù���\n"
              "�����Ե���Ǳ�ڵ�й©���ա�\n\n" NOR);
        write("��������Ĺ������룺");
        input_to("reset_ad_password", 1, ob);
        return;
    }
 
    // Check wizpass By Mudring...
    if ((id = ob->query("id")) && wiz_level(id) > 0)
    {
        write(HIR"��"WHT"��"HIG"��������Ӧ��WIZ����"WHT"��"NOR"");
#ifdef NO_CHECK_WIZPWD
        write(HIR"\n����㻹û���趨��ʦ���룬������س�����"NOR"");
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
        write("��������ĳ�������Ҫ�����Ԫ�����������Ĺ������룺");
        input_to("reset_ad_password", 1, ob);
        return;
    }
    my_pass = ob->query("password");
    if (stringp(my_pass) && crypt(pass, my_pass) == my_pass)
    {
        write(HIR "Ϊ�˰�ȫ�����ϵͳҪ�����������������ͨ���벻����ͬ��\n\n" NOR);
        write("������������Ĺ������룺");
        input_to("reset_ad_password", 1, ob);
        return;
    }

    ob->set_temp("ad_password", crypt(pass, 0));
    write("��������һ�����Ĺ������룬��ȷ����û�Ǵ�");
    input_to("confirm_reset_ad_password", 1, ob);
}

protected void confirm_reset_ad_password(string pass, object ob)
{
    string old_pass, id;

    write("\n");
    old_pass = ob->query_temp("ad_password");
    if (crypt(pass, old_pass) != old_pass)
    {
        write("����������Ĺ������벢��һ�����������趨һ�ι������룺");
        input_to("reset_ad_password", 1, ob);
        return;
    }

    ob->set("ad_password", old_pass);
    // Check wizpass By Mudring...
    if ((id = ob->query("id")) && wiz_level(id) > 0)
    {
        write(HIR"��"WHT"��"HIG"��������Ӧ��WIZ����"WHT"��"NOR"");
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
            write("�����һ����������ʱ��ֻ��" + chinese_number(time() - user->query("last_relogin")) +
                "���ӣ����Ժ��ٵ�¼��\n");
            user->set("last_relogin", time());
            destruct(ob);
            return;
        }
        if (user->is_net_dead())
        {
            reconnect(ob, user);
            return;
        }
        write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
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
                write(HIG"�Բ�����ողű��߳���Ϸ�����Ǵ�����ٳ������߰ɡ�\n"NOR);
                destruct(ob);
                destruct(user);
                return;
            }
            if (ob->query("last_on") < time() &&
                ob->query("last_on") > time() - 60 &&
                ! wiz_level(user))
            {
                write("�����һ���˳�ʱ��ֻ��" + chinese_number(time() - ob->query("last_on")) +
                      "���ӣ����Ժ��ٵ�¼��\n");
                destruct(user);
                destruct(ob);
                return;
            }

            user->set("last_save", time());
            if (err = catch(enter_world(ob, user)))
            {
                user->set_temp("error", err);
                msg = HIR "\n���޷�����������磬������ĵ�"
                      "������һЩ���⣬��Ҫ����ʦ��ϵ��\n\n" NOR;
                if (mapp(err))
                    msg += MASTER_OB->standard_trace(err, 1);
                user->set_temp("error_message", msg);
                tell_object(user, msg);
            }
            return;
        } else
        {
            destruct(user);
            write(HIR "\n�޷���ȡ������ݵ���������Ҫ����ʦ��ϵ��\n" NOR);
            write(WHT "�����ѡ�����´������(y/n)��" NOR);
            input_to("create_new_player", ob);
         }
    } else
    write(HIR "�޷���������ң�����Գ������µ�¼���Ǻ���ʦ��ϵ��\n" NOR);
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
        write("���½����wizpwd���趨�����ʦ���룡\n");
        check_ok(user);
#else
        write("��û���趨WIZ���룬����ϵϵͳ����Ա��\n");
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
            write("������ȷ��\n");
            check_ok(user);
            return;
        }
        else
        {
            write("�������\n");
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
        write("\n�Ǻðɣ��������ӵ�¼ʧ���ˡ�");
        destruct(ob);
        return;
    }

    write(HIW "\n���ڿ�ʼ���´��� " HIY + ob->query("id") +
          HIW " �����ҡ�\n" NOR);
    confirm_id(yn, ob);
}

protected void confirm_relogin(string yn, object ob, object user)
{
    object old_link;

    if (! yn || yn=="")
    {
        write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }   

    if (yn[0]!='y' && yn[0]!='Y')
    {
        write("�ðɣ���ӭ�´�������\n");
        destruct(ob);
        return;
    }

    if (user)
    {
        tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
                + " )����ȡ���������Ƶ����\n");
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
        write("������ҶϿ������ӣ�����Ҫ���µ�½��\n");
        destruct(ob);
        return;
    }

    reconnect(ob, user);
}

protected void confirm_id(string yn, object ob)
{
    if (this_object()->query_temp("newid/"+ob->query("id"))){
        write("�Ѿ�������ע�����id�ˡ�\n");
        destruct(ob);
        return;             
    }
    this_object()->set_temp("newid/"+ob->query("id"),1);

write(HIW
    "\nΪ�˱�֤�������İ�ȫ����ϷҪ���������������롣һ���ǹ�����\n"
    "�룬����������������ʧ����ͨ����ʱ��¼��Ϸ���������޸���ͨ\n"
    "���롣ƽʱ��ʹ����ͨ�����½���������Ƶ����ʹ�ù��������Ե�\n"
    "��Ǳ�ڵ�й©���ա�\n\n"
NOR);
    write("���趨���Ĺ������룺");
    input_to("new_ad_password", 1, ob);
}

protected void new_ad_password(string pass, object ob)
{
    write("\n");
    if (strlen(pass) < 5)
    {
        write("��������ĳ�������Ҫ�����Ԫ�����������Ĺ������룺");
        input_to("new_ad_password", 1, ob);
        return;
    }
    ob->set_temp("ad_password", crypt(pass, 0));
    write("��������һ�����Ĺ������룬��ȷ����û�Ǵ�");
    input_to("confirm_ad_password", 1, ob);
}
protected void confirm_ad_password(string pass, object ob)
{
    string old_pass;

    write("\n");
    old_pass = ob->query_temp("ad_password");
    if (crypt(pass, old_pass) != old_pass)
    {
        write("����������Ĺ������벢��һ�����������趨һ�ι������룺");
        input_to("new_ad_password", 1, ob);
        return;
    }

    ob->set("ad_password", old_pass);
    write(HIM "��ͨ��������ƽʱ��¼��Ϸʱʹ�õģ���Ϸ�п���ͨ�� PASSWD ����\n"
          "���޸�������롣\n\n" NOR);
    write("�����������ͨ���룺");
    input_to("new_password", 1, ob);
}
protected void new_password(string pass, object ob)
{
    string ad_pass;
    
    write("\n");
    if (strlen(pass) < 5 ) {
        write("��������Ҫ������ַ���ɣ��������������룺");
        input_to("new_password", 1, ob);
        return;
    }
    if (stringp(ad_pass = ob->query("ad_password")) &&
        crypt(pass, ad_pass) == ad_pass)
    {
     write(HIR "��ע�⣬Ϊ�˰�ȫ�����ϵͳҪ����Ĺ����������ͨ���벻����ͬ��\n\n" NOR);
        write("����������������ͨ���룺");
        input_to("new_password", 1, ob);
        return;
    }
      ob->set_temp("password", crypt(pass, 0));
    write("��������һ���������룬��ȷ����û�Ǵ�");
    input_to("confirm_password", 1, ob);
}

protected void confirm_password(string pass, object ob)
{
    string id, old_pass;
    
    write("\n");
    old_pass = ob->query_temp("password");
    if( crypt(pass, old_pass)!=old_pass ) {
        write("��������������벢��һ�����������趨һ�����룺");
        input_to("new_password", 1, ob);
        return;
    }
    ob->set("password", old_pass);
    if (ob->query_temp("reset_password"))
    {
        // �����û��޸��Լ��������֧���̣����Ǵ���
        // �û���֧�����ת�Ƶ� check_ok ��������ִ
        // �С�
        ob->save();
        // Check wizpass By Mudring...
        if ((id = ob->query("id")) && wiz_level(id) > 0)
        {
            write(HIR"��"WHT"��"HIG"��������Ӧ��WIZ����"WHT"��"NOR"");
            input_to("get_wizpwd", 1, ob);
        }
        else
            check_ok(ob);
        return;
    }
write( @TEXT

�������Լ���һ������������������������֡�������ֽ�
���������������е�����������󽫲����ٸ��ġ��벻Ҫ
ȡһЩ���Ż�����������������ŵ����֡�

TEXT
);
    write("�����������֣�");
    ob->set_temp("get_name",0);
    input_to("get_name", ob);
}

protected void get_name(string arg, object ob)
{
    string result;
    if (!check_legal_name(ob, arg))
    {
        write("�����������֣�");
        input_to("get_name", ob);
        return;
    }
    if ( stringp(result = NAME_D->invalid_new_name(arg)) )
    {
        write("�Բ���" + result);
        write("\n��������������" HIG "��������" NOR "��");
        input_to("get_name", ob);
        return;
    }
    ob->set("name", arg);
    printf("%O\n", ob);
    write("���ĵ����ʼ���ַ������ϸ��д����ס������Ϸ��email����֤��ݣ�");
    input_to("get_email",  ob);
}

protected void get_email(string email, object ob)
{
    write("\n");

    if (strsrch(email, "@") == -1 || strsrch(email, ".")==-1 || strlen(email)<9) {
        write("�����ʼ���ַ��Ҫ�� id@address�ĸ�ʽ��\n");
        write("���ĵ����ʼ���ַ��");
        input_to("get_email", ob);
        return;
    }
    ob->set("email", email);

    write("��Ҫ���ݽ�ɫ�����ͣ�\n"
          "[" HIC "1" NOR ". ������  "
          HIC "2" NOR ". ħ��ʦ  "
          HIC "3" NOR ". �ս���  "
          HIC "4" NOR ". ������  "
          HIC "5" NOR ". ������  "
          HIC "6" NOR ". ���ڵ���ʹ��] ("
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
        write ("�Բ�����ֻ��ѡ��1-6�����»س�ֱ��ѡ�񰵺ڵ���ʹ�ߡ�\n\n");
        write("��Ҫ���ݽ�ɫ�����ͣ�(6)");
        input_to("get_type", ob);
        return;
    }

    switch(n)
    {
    case 1:
        ob->set_temp("type", "������");
        break;
    case 2:
        ob->set_temp("type", "ħ��ʦ");
        break;
    case 3:
        ob->set_temp("type", "�ս���");
        break;
    case 4:
        ob->set_temp("type", "������");
        break;
    case 5:
        ob->set_temp("type", "Ұ����");
        break;
    case 6:
        ob->set_temp("type", "���ڵ���ʹ��");
        break;
    }

    write("��ѡ����" HIC + ob->query_temp("type") + NOR "�Ľ�ɫ��\n");

    write("\n��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
    input_to("get_gender", ob);
}

protected void get_gender(string gender, object ob)
{
    object user;

    write("\n");
    if (gender=="")
    {
        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob);
        return;
    }

    if (gender[0]=='m' || gender[0]=='M')
        ob->set_temp("gender", "����");
    else if (gender[0]=='f' || gender[0]=='F')
        ob->set_temp("gender", "Ů��" );
    else
    {
        write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob);
        return;
    }

    if (find_body(ob->query("id")))
    {
        write(HIR "�����������Ѿ���¼������������ˣ���"
              "�˳��������ӡ�\n" NOR);
        destruct(ob);
        return;
    }

    ob->set("body", USER_OB);
    if (! objectp(user = make_body(ob)))
    {
        write(HIR "\n���޷���¼����µ����������ѡ��\n" NOR);
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
        write("��û��Ȩ�޴�����ҡ�\n");
        return 0;
    }
    seteuid(getuid());
    user = new(USER_OB);

    if(!user)
    {
        write("���ڿ������������޸��������ĳ�ʽ���޷����и��ơ�\n");
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
    user->set("title", "����ƽ��");
    user->set("birthday", time() );
    user->set("potential", 99);
    user->set("scorepoint",0);
    user->set("level",1);
    user->set("food", user->max_food_capacity());
    user->set("water", user->max_water_capacity());
    user->set("channels", ({ "chat","rumor","job","sldh","mete","sj", "sos" }));

    // ��¼����
    NAME_D->map_name(user->query("name"), user->query("id"));
}

varargs void enter_world(object ob, object user, int silent)
{
    int nCount;
    string startroom;
    string ip_number;
    string ip_from;
        ////////////
	// Add for ����֪ͨ By Aeddy 2004-1-5
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

write(CYN"     �ԡԡԡԡԡԡԡԡԡԡԡ�"HIR+MUD_NAME+"������Ϣ"NOR CYN"�ԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
write(HIY"     ��  ����ϵͳȨ��Ŀǰ�ǣ�"HIC + wizhood(user) + "\n"NOR);
write(HIY"     ��  ���ϴ����ߵĵ�ַ�ǣ�"HIC + ob->query("last_from") + "\n"NOR);
write(HIY"     ��  ���ϴ����ߵ�ʱ���ǣ�"HIC + ctime(ob->query("last_on"))+ "\n"NOR);        
write(HIY"     ��  ���������ߵ�ʱ���ǣ�"HIC + ctime(time()) + "\n"NOR);
write(HIY"     ��  ���ǵ� "HIR+chinese_number(nCount)+NOR HIY" ������"+CHINESE_MUD_NAME+"��\n");
write(NOR CYN"     �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n\n"NOR);        

        if (file_size("/etc/notice") > 0)
        {
            write(HIC"     �ԡԡԡԡԡԡԡԡԡԡԡ� "HIR"����֪ͨ"NOR HIC" �ԡԡԡԡԡԡԡԡԡԡԡ�\n");
            write(NOR"     " + color_filter(read_file("/etc/notice")));
            write(HIC"     �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR);
        }

        user->set_temp("last_damage_from", "Ī�������");
        user->set_temp("logon_mudage", user->query("mud_age"));

        if (user->query("no_gift"))
        {
            user->move("/d/wiz/init",1);
        } else
        {
            write("�밴�س�����......\n");
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
                write("���ϴ��˳��ĵط��Ѿ���ʧ�ˡ�\n");
                startroom = START_ROOM;
            }

            user->move(startroom);
            user->set("startroom", startroom);

            tell_room(startroom, user->query("name") +
                      "���߽���������硣\n", ({user}));
        }      

        ip_from = __DIR__"sited"->seek_ip_address(ip_number);
        CHANNEL_D->do_channel(this_object(), "sys",
            sprintf(NOR WHT "%s�� " HIG "%s" NOR WHT "���߽���,IP���ԣ�"HIG"%s"NOR,
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
     // Add for QQ����֪ͨ By Aeddy 2004-1-5
	if(mapp(user->query("qq"))
	   && sizeof(user->query("qq"))!=0
	   &&!user->query("env/invisibility")) {
	qqfriends = keys(user->query("qq"));
	 for(qqnum=0;qqnum<sizeof(qqfriends);qqnum++)
                {
				qqob=find_player(qqfriends[qqnum]);
				tell_object(qqob,BLINK HIG+"������ʹ֪ͨ������ĺ���"+user->query("name")+"["+capitalize(user->query("id"))+"]�����ˣ���\n"+NOR);
		}
         }
     ////////////////////////////////////////////////////////

    if(wizardp(user))
    {
        if (!ob->query("wiz_password"))
            write(HIR+BLINK"����WIZPWD�趨��Ӧ��WIZ���룡\n"NOR);
        CHANNEL_D->do_channel( this_object(), "wiz",
            sprintf(NOR "%s" HIY " �� " HIG "%s" HIY " �������ߡ�",
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
        tell_room(environment(user), user->query("name") + "�������߻ص�������硣Good Luck!\n",({user}));
    CHANNEL_D->do_channel(this_object(), wiz_level(user)?"wiz":"sys",
        sprintf("%s��%s�������߽��롣", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_number(user)));
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
        write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
        return 0;
    }
    while(i--)
        if( id[i]<'a' || id[i]>'z' )
        {
            write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
            return 0;
        }
    legalid = explode(read_file(BANNED_ID), "\n");
    for (i=0; i<sizeof(legalid); i++)  
    {
        if ( id == legalid[i] )  
        {
            write("�Բ����������ֻ���������˵����š�\n");
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
        write("�Բ�������������ֱ�����һ�����������֡�\n");
        return 0;
    }
    while(i--)
    {
        if( i%2==0 && !is_chinese(name[i..<0]) )
        {
            write("�Բ��������á����ġ�ȡ���֡�\n");
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

