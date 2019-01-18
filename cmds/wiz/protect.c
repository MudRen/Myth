//Bula 3.18
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who,obj;


        if( !arg ) {
		if(me->query_temp("protect") ) {
			if( objectp(obj=find_living(me->query_temp("protect")) )){
				tell_object(me, "���������ڱ���"+obj->query("name")+"��\n");
				return 1;
			}
		}
		tell_object(me,"��Ҫ����ʲô�ˣ�\n");
		return 1;
	}
	
	if( arg=="me" || arg==me->query("id") )  
                return notify_fail("��Ҫ����ʲô�ˣ�\n");

        if( arg=="none") {
		if( !me->query_temp("protect") ){
			tell_object(me, "�㲢û�б����κ��ˡ�\n");
			return 1;
		}
                if( objectp(obj=find_living(me->query_temp("protect")) )) {
                        tell_object(obj, me->query("name")+"�����������ˡ�\n");
			tell_object(me, "���������"+obj->query("name")+"��\n");
			me->delete_temp("protect");
			return 1;
		}
		tell_object(me, "������������ˡ�\n");                
		me->delete_temp("protect");                
		return 1;
        }

	if( !objectp(who=present(arg, environment(me))))
		return notify_fail("��Ҫ����ʲô�ˣ�\n");

	if( !living(who) )
		return notify_fail("�㲻�ܱ���"+who->query("name")+"��\n");

	if( me->query_temp("protect") == who->query("id") )
		return notify_fail("���Ѿ��ڱ���������ˡ�\n");

        if( time()-30 <= (int)me->query_temp("protect_time") )
                return notify_fail("�㱣��̫�����ˡ�\n");

	if((int)me->query_condition("no_pk_time") > 480 )
		return notify_fail("�����ɱ��̫�ࡣ����\n");

	if( me->query_temp("protect") ) {
                if( objectp(obj=find_living(me->query_temp("protect")) )) {
                        tell_object(obj, me->query("name")+"�����������ˡ�\n");
			tell_object(me, "���������"+obj->query("name")+"��\n");
		}
        }

	message_vision(HIC"$N��ʼ����$n��\n"NOR, me, who);

	who->set_temp("protected", 1);
	who->set_temp("protect_ob", me->query("id"));
	me->set_temp("protect", who->query("id"));
	me->set_temp("protect_time", time());
	return 1;

}

int help(object me)
{
   write( @HELP
ָ���ʽ: protect [<����>|<NPC>|none]

��ʼ��������������ĳ�ˡ�
HELP
   );
   return 1;
}
