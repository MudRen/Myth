//whotime.c
//�鿴��ҵĳɳ��ٶ�

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string str)
{
    object where, ob, *ob_list;
    int i, age, exp, dx, time;
    string stri;
int sudu;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG" ���        ID        ����  ����ʱ��     ����/min    ����/min\n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
        age  = (ob->query("mud_age") - ob->query_temp("logon_mudage"));
        time = (time()-ob->query_temp("logon_time"));
    sudu = (ob->query("combat_exp") + ob->query("daoxing")) * 60 /(ob->query("mud_age")>86400?ob->query("mud_age"):86400);
        
        if (age < 60)  age = 60;

        exp = (ob->query("combat_exp") - ob->query_temp("logon_exp")) * 60 / age;
        dx  = (ob->query("daoxing") - ob->query_temp("logon_daoxing")) * 60 / age;        

        str += sprintf(WHT"%-10s:  ",ob->name());
        str += sprintf(HIR"%-10s ", ob->query("id"));
        str += sprintf(HIG"%-4d ", ob->query("age"));
        str += sprintf(HIY"%-12s ", FINGER_D->age_string(time));
        str += sprintf(HIM"%-12d ", exp);
        str += sprintf(HIM"%-12d ", dx);
        str += sprintf(HIM"%-12d ", sudu);
        str += sprintf("\n"NOR);

    }
    str += "��������������������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������С�\n", str, sizeof(ob_list));
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;
        if( wizardp(ob2) && !wizardp(ob1) ) return 1;
        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);
        
        return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��whotime

��ҳɳ��ٶȲ�ѯ��
HELP
        );
        return 1;
}

