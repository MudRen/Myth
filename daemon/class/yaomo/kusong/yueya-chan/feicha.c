//Cracked by Roath
// �ɲ���ա�     evil     2000.5.15

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("yueya-chan",1) ;
	if ( extra < 80) return notify_fail("������������������죡\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ɲ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
message_vision(HIC "$N˫��һ��һ�зɲ���գ����е�"+ weapon->name()+  "�ɳ�����$n��" NOR,me,target);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	if( weapon->unequip()) weapon->move(environment(me));
	me->start_busy(2);
	return 1;
}
