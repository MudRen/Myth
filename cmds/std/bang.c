//Cracked by Roath
// bang.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *t;
	string ss,st,t1,t2,s1,s2;

	if (!arg) return notify_fail("�÷�����!\n");

	ss=me->query("marks/����");
	if (ss!=0)
	{
		t1="marks/"+ss;
		st=me->query(t1);
	}
	if( arg=="dismiss" ) {
		if( ss==0 )
			return notify_fail("�����ڲ�û�вμ��κΰ�ᡣ\n");
		write("��������"+ss+"��\n");
		me->delete("marks/����");
		me->delete(t1);
		me->set("title","��ͨ����");
		return 1;
	}
	if( sscanf(arg, "with %s", arg)==1 ) {
		object ob;
		if( !(ob = present(arg, environment(me)))
		|| 	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("�����˭��Ϊͬ��Ļ�飿\n");

		s1=ob->query("marks/����");
		if (s1!=0)
		{
			t2="marks/"+s1;
			s2=ob->query(t2);
		}
	       	if( me==(object)ob->query_temp("pending/bang") ) 
		{
			if ((ss!=0)&&(s1!=0))
			{
				ob->dellete_temp("pending/bang");
				return notify_fail("˫���������ᡣ\n");
			}
		}		
		if( (ss==0) || (st=="����" )) {
		       if( me==(object)ob->query_temp("pending/bang") ) {
				if( ss==0 ) {
					me->set("marks/����",s1);
					me->set(t2,"����");
					message_vision("$N��������$n��"+s1+"��\n", me, ob);
				} else {
					ob->set("marks/����",ss);
					ob->set(t1,"����");
					message_vision("$N������$n����"+ss+"��\n", me, ob);
				}
				ob->dellete_temp("pending/bang");
				return 1;
			} else {
				if (st=="����")
				{
					message_vision("$N����$n����"+ss+"��\n", me, ob);
					tell_object(ob, YEL "�����Ը����룬���� bang with " + me->query("id") + "��\n" NOR);
				} else {
					if (s2=="����")
					{
						message_vision("$N�������$n��"+s1+"��\n", me, ob);
						tell_object(ob, YEL "�����ͬ����룬���� bang with " + me->query("id") + "��\n" NOR);
					} else {
						return notify_fail("ֻ���������������ᡣ\n");
					}
				}
				me->set_temp("pending/bang", ob);
				return 1;
			}
		} else
			return notify_fail("ֻ�ж�������������˼��롣\n");
	}
}

int help(object me)
{
	write(@HELP
���ָ��ʹ�÷���:

bang with <ĳ��> - ��ĳ��ͬ��. ����Ҫ˫����ͬ�����������һ���Ƕ����Ż���Ч��
bang dismiss     - �뿪���. 
HELP
	);
	return 1;
}
