// heal.c

#include <ansi.h>

int cast(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");
	if(me->query("family/family_name")!="�Ϻ�����ɽ")
                return notify_fail("���Ƿ��ŵ���,��������Ű��壡\n");

	if( (int)me->query("mana") < 50 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
		return notify_fail("�㾫��ʵ�ڲ��ã�ֻ��һ�˷�����������Σ�գ�\n");

	write( HIW "��ȫ����ɣ����ȶ�������ʼ�������⡣\n" NOR);
	message("vision",
		HIW + me->name() + "���ȶ�������ʼ�������⡣�����³�һ�����������������ö��ˡ�\n"NOR,
		environment(me), me);

	me->receive_curing("sen", 10 + (int)me->query_skill("spells")/5 );
	me->add("mana", -50);
	me->set("mana_factor", 0);

	return 1;
}
