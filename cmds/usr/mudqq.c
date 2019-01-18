// by canoe 2001-03-27
#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me,string arg)
{
        object ob;
        string* f_ids;
        mapping friends;
        string str,s1,s2;
        string myid;
        int i;

        friends = me->query("qq");
        myid=me->query("id");
        if(!arg) 
        {
                if(!friends 
                || !mapp(friends)
                ||  (sizeof(friends) == 0))
                        return notify_fail(HIR"    ���MUD_QQ�ϲ�û�м�������ѡ�\n"NOR);
                f_ids = keys(friends);
                write(HIR+"\t�������������������ڵ����ѩ�������������\n"+NOR);
                str = "";
                for(i=0;i<sizeof(f_ids);i++)
                {
				ob=find_player(f_ids[i]);
            		str += "\t  "+HIG+friends[f_ids[i]]+"("+capitalize(f_ids[i])+")"+NOR;
				if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
                        str += NOR CYN+"\t��    ��  \n"+NOR;
				else
                        str +=NOR HIW+"\t��    ��   \n"+NOR;
                }
                write(str);
                write(HIR+"\t����������������������������������������\n"+NOR);
                return 1;
        }
        if(sscanf(arg,"%s %s",s1,s2) ==2)
        {
                if(s1 == "-a")
                {
          if( !(ob = find_player(s2))
	  ||	!living(ob)
	  ||	!ob->is_character()
	  ||    ob->query("env/invisibility")   )
	    return notify_fail("û������ˣ��޷���Ӻ���������\n");
                        if(myid == s2)
                                return notify_fail("û�����Ҫ�ɣ�\n");
                        if(sizeof(friends)>30)
                                return notify_fail("��ĺ�������̫���ˣ���ɾ��Щ�����õĺ���!\n");
                        if(me->query("qq/"+s2))
                        return notify_fail(ob->query("name")+"�Ѿ�������ĺ��������ڣ�\n");
                        if(ob->query_temp("renzheng/"+myid)) return notify_fail("���Ѿ���Է����͹������ˣ�\n");
                        if(ob->query("env/qq_no")) return notify_fail("�Է��ܾ�������ѣ���֪ͨ�Է�unset qq_no��\n");
                        if(ob->query("env/qq_renzheng")) {
                        write("�Է���Ҫ��֤�����Ѿ���"+ob->query("name")+"��������֤����\n"); 
                        tell_object(ob,BLINK HIW+me->query("name")+"["+capitalize(myid)+"]���㷢����֤������ʹ��mudqq -r ͨ����֤.\n"+NOR);
                        ob->set_temp("renzheng/"+myid,me->query("name"));
                      //  me->set_temp("qqadd/"+ob,ob->query("name"));
                        return 1;
                        }
                        else me->set("qq/"+s2,ob->query("name"));
                        write("�㽫"+ob->query("name")+"�������������\n");
                        if(living(ob))
                        tell_object(ob,BLINK HIG+me->query("name")+"["+capitalize(myid)+"]����������ĺ��ѣ�\n"+NOR);
                        ob->set("qqof/"+myid,me->query("name"));
                        return 1;
                }
                else if(s1 == "-d")
                {
                       // if(!objectp(ob = find_player(s2))
                       // ||    ob->query("env/invisibility") )
                       //         return notify_fail("û����ˣ�\n");
                        if(!me->query("qq/"+s2))
                        return notify_fail("��û������ѣ�\n");
                        if (me->delete("qq/"+s2))
                   write(HIG"���"+s2+"�Ӻ���������ɾ���ˣ�\n"NOR);
                        else return notify_fail("ɾ������,����ƴ����?\n");
                        return 1;
                }
                else if(s1=="-r")
                {
                 if( !(ob = find_player(s2))
	            ||	!living(ob)
	            ||	!ob->is_character()
	            ||    ob->query("env/invisibility")   )
	    return notify_fail("û������ˣ��޷�ͨ����֤��\n");
	    if(!me->query_temp("renzheng/"+s2) ) return notify_fail("�Է���û�����㷢�͹�����\n");
           // if(me->query("qq/"+s2))
                  //    return notify_fail(ob->query("name")+"�Ѿ�������ĺ��������ڣ�\n");
             if(living(ob)){
             tell_object(ob,BLINK HIG+me->query("name")+"["+capitalize(myid)+"]�Ѿ�ͨ������������֤��\n"+NOR);  
             me->delete_temp("renzheng/"+s2);
             write(HIG+"��ͨ����"+ob->query("name")+"����֤����\n"+NOR);
             ob->set("qq/"+myid,me->query("name"));         
                        return 1;
                         }
                 }
        }
        write("�÷�:qq [-a|-d|-t] name\n");
        return 1;
} 

int help(object me)
{
   
        write(@HELP
ָ���ʽ : mudqq [-a|-d|-r] [<ĳ��>]
����������������鿴���,�����ѡ�
-a <ĳ��>: ���ĳ��Ϊ����
-d <ĳ��>: �Ӻ���������ɾ��ĳ��
-r <ĳ��>: �ڶԷ����㷢����֤����ʱ,�ô�����ͨ���Է���֤����.
���Ӳ��� : ��ʾ������к�������״��.
set qq_no        �ܾ�����qq����
set qq-talk      ����qq��������
set qq_renzheng  ���������Ҫ��֤
HELP
    );
    return 1;
}


