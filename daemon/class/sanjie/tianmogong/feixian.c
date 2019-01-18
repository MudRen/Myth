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
		return notify_fail("��Ҫ��˭ʩչ��������ɡ���\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("���޷����о�����׼��\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("�𱦱�˵��Ƚ����˸������������ˣ�\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
		target, 
		success_adj, 	
		damage_adj, 	
		"both", 		
		HIC "$N�������˼������ģ�����һ�����𱦱��ڴˣ���������ֳ�һλ������������ʿ��\nֻ����˫�ּ�������ಡ���һ����һ��������Ϣ�Ľ�����$n������£�\n" NOR,
		HIC "���������$n����͸���������ʱѪ���ɽ���\n" NOR, 
		HIC "ֻ��$n����һ��������������$n���������\n" NOR, 
                HIC "����$n�Է���һ����������ಡ���һ������$N��\n" NOR,

		HIC "���������$n����͸���������ʱѪ���ɽ���\n" NOR
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

