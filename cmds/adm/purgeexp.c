// purge.c

#include <ansi.h>
#define SYNTAX  "指令格式：purge [<低于武学>] | <使用者姓名> because <原因>\n"

inherit F_CLEAN_UP;

private int do_purge_players(int exp);

int main(object me, string arg)
{
        string name, reason;
        string status;
        int exp;
        if (! SECURITY_D->valid_grant(me, "(admin)")) return 0;

        status = wizhood(me);
        if( me!=this_player(1)
        || wiz_level(me) < wiz_level(status) )
                return notify_fail("你没有权力使用这个指令。\n");

        if( !arg ) return notify_fail(SYNTAX);

        if( sscanf(arg, "%d", exp) && exp >= 0) return do_purge_players(exp);

        if( sscanf(arg, "%s because %s", name, reason)!=2 )
                return notify_fail(SYNTAX);

        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("没有这位使用者。\n");
        if( (string)SECURITY_D->get_status(name)!="(player)" )
                return notify_fail("非玩家档案不能被删除。\n");

//        NAME_D->remove_name(arg->query("name"), arg->query("id"));
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "使用者 " + capitalize(name) + " 被删除掉了。\n");
        log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));

        return 1;
}

private int do_purge_players(int exp)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;
object who;

        if(exp > 400000 ) return notify_fail("wx应该小于400000。\n");
        seteuid(getuid());
//      message("system", "\n*** 整理玩家储存档中，请稍候.... ***\n", users());
        write("处理中：\n");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write("目录"+dir[i]+": 玩家");
                ppls = get_dir(DATA_DIR + "user/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
               
                log_file("static/PURGE", sprintf("[%s] %s cleaned up characters who didn't more than %d exps\n",
                ctime(time())[0..15], geteuid(this_player(1)), exp));
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" )
                                        continue;

// Modified by dream on June 26, 1997 to avoid incorrect touching
// from outer sources like shell modification
//                      info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
who =new(USER_OB);
who->set("id", name);
if (! who->restore())
 continue;
                        if( (who->query("combat_exp"))< exp && who->query("balance")<50000) {
                                rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
        // write(" "+name);
  log_file("static/PURGE", sprintf(" %s ",name));
                                count ++;
                        }
destruct(who);
                }
   //write(" 被清除掉了。\n");
   log_file("static/PURGE", sprintf("  被清除掉了。\n"));
        }
        write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
        write( count + " 个超过 " + exp + " 武学未上线的使用者被清除掉了。\n");
        write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d exps\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, exp, ppl_cnt - count));


        return 1;
}

int help(object me)
{
write(@HELP
指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>

清除一个使用者或清除低于某些武学使用者。
HELP
        );
    return 1;
}


