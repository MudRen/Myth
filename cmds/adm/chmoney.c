//Cracked by Roath
// checkhp.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG"   �������           ��Ǯ        \n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
        if (!wizardp(ob)){
        str += sprintf(WHT"%-16s:  ",ob->name()+"("+ob->query("id")+")");
        str += sprintf(GRN"%-10d ", ob->query("balance"));
        }
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
        
        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��checkhp

��ѯ���ϵ�������ҵ�Ǯ��
HELP
        );
        return 1;
}



