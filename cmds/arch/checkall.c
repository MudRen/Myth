//Cracked by Roath

inherit F_CLEAN_UP;
#include <ansi.h>
int help(object me);

int main(object me, string arg)
{
        int i, j;
        string *dir, *ppls, name,str,str2="\n";
        object ob,obj;

        if (! SECURITY_D->valid_grant(me, "(admin)")) return 0;

        seteuid(getuid());
        message("system", RED"\n ������Ҵ��浵�У����Ժ�....\n" NOR, users());
        write("�����У�\n");
        dir = get_dir(DATA_DIR + "login/");
        str="\n";
        ob=new("/obj/user/user.c");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                                if( (string)SECURITY_D->get_status(name)!="(player)" ){
                                    write(BOLD+"�ų���ʦ"+name+"\n"+NOR);
                                        continue;
                                }
                               // if (!ob->new(name))  continue;
                                 obj=present("cash",ob);
                                if (ob->query("combat_exp")>=10000 || (int)ob->query("potential") - (int)ob->query("learned_points")>100000 || ob->query("max_force")>2500 )
                                        str+=sprintf("%10s(%s) ����:%10d,Ǳ��:%10d,����:%10d,����ʱ��:%d\n",ob->name(),name,ob->query("combat_exp"),(int)ob->query("potential") - (int)ob->query("learned_points"),ob->query("max_force"),ob->query("mud_age")/86400);
                                
                        }

                  if  ( obj && obj->query_amount()>100)
                  str2+=sprintf("%10s(%s) ���Ͻ�Ʊ��:%d\n",ob->name(),name,obj->query_amount());
                }
        }
        destruct(ob);
     log_file("check_users",str);
     log_file("check_users",str2);
        me->start_more(str+str2);
        message("system", BOLD"\n �������!\n" NOR, users());
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��checkall

HELP
        );
    return 1;
}


