// ������

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int delay,myunarmed;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[������]ֻ����ս����ʹ��\n");

        if (!PFM_D->valid_family(me, "������"))
                return notify_fail(HIR"����������"+NOR"�ǽ���������֮�ܣ�\n");

	myunarmed=(int)me->query_skill("changquan",1);
	if(myunarmed<60) 
		return notify_fail("��ĳ�ȭ��Ϊ������޷�ʹ��[������]��\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIY "$N��ȭ�������л���ȭ֮�ذ���[������]��$n��ȥ��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIB "$n��һ��ȭ��ɨ�У����β�������������\n" NOR;
                delay = 2+random(myunarmed/20);
		target->start_busy(delay);
//                me->start_busy(random(3));
	} else {
		msg += HIG "����$p�����˼���������������ȭ�磡\n" NOR;
                me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
