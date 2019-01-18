// transfer.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
	int force, trans;
	int tforce, tmaxforce;

	if( !target || target==me || !living(target) )
		return notify_fail("��Ҫ����������˭��\n");

        if(target->is_busy())
	        return notify_fail("�Է�����æ���ء�\n");

        if(target->is_fighting())
	        return notify_fail("�Է�����æ���ء�\n");

	if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
		return notify_fail(target->name() + "��ʹ�õ��ڹ����㲻ͬ��\n");

	if( (int)me->query("force") <= (int)me->query("max_force") )
		return notify_fail("����������㡣\n");

	force = me->query("force") - me->query("max_force");

	if( force/2 < 1 ) return notify_fail("����������㡣\n");
	me->add("force", - force / 2 );
	message_vision("$N����������$n���ģ������������������͹�ȥ��\n", me, target);
	if( random(force/3) > (int)me->query_skill("force") )
		return notify_fail("��ʧ���ˡ�\n");

	tforce = (int)target->query("force");
	tmaxforce = (int)target->query("max_force");
	write("Ok.\n");
	tell_object(target, HIY "�����һ��������" + me->name() + "�����ƴ��˹�����\n" NOR);
	me->start_busy(2+random(4));
	target->start_busy(2+random(4));
        if( tforce < tmaxforce ) {
	   tforce += force/6;
	   if(tforce > tmaxforce) tforce = tmaxforce;
	   target->set("force", tforce);
	}
	return 1;
}
