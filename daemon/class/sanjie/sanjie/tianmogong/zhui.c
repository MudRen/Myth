// zhui.c ��ħ׶

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 100;
	damage_adj = 100;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ����ħ׶����\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("���޷����о�����׼��\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("������һ�ϣ����������У�\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
		target, 
		success_adj, 	
		damage_adj, 	
		"both", 		
		HIC "$N"NOR+HIC"�������˼������ģ���˫����������ȫ�������ת������$n"NOR+HIC"�����ȥ��\n" NOR,
		HIC "���$N"NOR+HIC"��$n"NOR+HIC"����͸���������ʱѪ���ɽ���\n" NOR, 
		HIC "ֻ��$n"NOR+HIC"����һ����$N"NOR+HIC"���ò���$n"NOR+HIC"�űߣ����ܷ�ɰ��ʯ��\n" NOR, 
        	HIC "����$n"NOR+HIC"�Է���һ����$N"NOR+HIC"����һ�ϣ�\n" NOR,
		HIC "���$n"NOR+HIC"������ת��Ѫ���������ſ��³�һ�����Ѫ��\n" NOR
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

