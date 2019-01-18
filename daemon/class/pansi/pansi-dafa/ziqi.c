// drainerbolt.c
//2001,lestat
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 20 )
		return notify_fail("��ķ��������ߣ�\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ��������\n");

	if((int)me->query("mana") < 100 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -25);
	me->receive_damage("sen", 20);

	if( random(me->query("max_mana")) < 20 ) {
		write("��ʧ���ˡ�\n");
		return 1;
	}

	msg = HIM "$N�����૵��������ģ�����һ�ӣ����о���һ����������$n��\n\n" NOR;

	ap = me->query_skill("spells");
	extradam = ap/2;
	ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  MAG "������͡���һ����������$p����͸��������ϳ�һ���������߲ʹ�������������\n"
					"��ת�����ִ�$N����ע��$P�����ڣ�\n" NOR;
			me->receive_heal("sen", target->receive_damage("sen", damage,me,"cast"));
			target->receive_wound("sen", damage/3, me,"cast");
			me->improve_skill("pansi-dafa", 1, 1);
		} else
			msg += HIB"������͡���һ����������$p����͸�������������Ϣ��������£�\n"NOR;
	} else
		msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}

