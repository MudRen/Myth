
// make friend with sb
// by driftpho@YSZZ

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me,string arg)
{
        object ob;
        string* f_ids;
        mapping friends;
        string str,s1,s2;
        int i;

        friends = me->query("friends");
        if(!arg) 
        {
                if(!friends 
                || !mapp(friends)
                ||  (sizeof(friends) == 0))
                        return notify_fail("�㻹û�������أ�\n");
                f_ids = keys(friends);
        f_ids = filter_array(f_ids, "filter_fri");
                write("�����ڵ������У�\n");
                str = "";
                for(i=0;i<sizeof(f_ids);i++)
                {
                        str += "  "+friends[f_ids[i]]+"("+f_ids[i]+")    ";
                        str += "״̬:" + (find_player(f_ids[i])? "����\n":"����\n");
                }
                write(str);
                return 1;
        }
        if(sscanf(arg,"%s %s",s1,s2) ==2)
        {
                if(s1 == "-a")
                {
                        if(!objectp(ob = find_player(s2)))
                                return notify_fail("û�����ң�\n");
// By mudring@sjsh
if (wizardp(ob)) return notify_fail("û�����ң�\n");
                        if(me->query("id") == s2)
                                return notify_fail("û�����Ҫ�ɣ�\n");
                        if(sizeof(friends)>20)
                                return notify_fail("��ĺ���Ҳ̫���˰�!\n");
                        if(me->query("friends/"+s2))
                        return notify_fail(ob->query("name")+"�Ѿ�����������ˣ�\n");
                        me->set("friends/"+s2,ob->query("name"));
                        write("�㽫"+ob->query("name")+"�������������\n");

                        if(living(ob))
                        tell_object(ob,me->query("name")+"["+me->query("id")+"]����������ĺ���������\n");
                        ob->set("friendof/"+me->query("id"),me->query("name"));
                        return 1;
                }
                else if(s1 == "-d")
                {
                        if(!objectp(ob = find_player(s2)))
                                return notify_fail("û����ˣ�\n");
                        if(!me->query("friends/"+s2))
                        return notify_fail("��û������ѣ�\n");
                        me->delete("friends/"+s2);
                        write("���"+ob->query("name")+"�Ӻ���������ȥ���ˣ�\n");
                        return 1;
                }
        }
        write("�÷�:friend [-a|-d] name\n");
        return 1;
} 
int filter_fri(string arg)
{
        if (arg == "helpler" || arg == "cigar" || arg =="ffff" || arg == "junhyun"|| arg == "lll"|| arg == "waiwai"|| arg == "leoy"|| arg == "koker"|| arg == "adier"|| arg == "passion"|| arg == "zangma"|| arg == "mudring" )
        return 0;
                return 1;
}

int help(object me)
{
        string desc_dx, desc_fali, desc_exp;

        write(@HELP
ָ���ʽ : friend [-a|-d] [<ĳ��>]

����������������鿴���,�����ѡ�
HELP
    );
    return 1;
}
