#include <ansi.h>

inherit SSERVER;

int scribe(object me,object ob)
{
	object seal;

	if( (int)me->query("mana") < 100)
		return notify_fail("��ķ������㡣\n");
	if( (int)me->query("sen") < 100)
		return notify_fail("��ľ����޷����С�\n");
	
	
	message_vision("$Nҧ����ָ���������ҷ�ֽ�ϻ��˼��¡�\n", me);
	
	destruct(ob);

	seteuid(getuid());
	seal=new("/d/jjf/obj/find_seal");
	seal->move(me);
	seal->invocation(me);

	me->start_busy(2);
	return 1;
}
	
