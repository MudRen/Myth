// Jiz
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 110;
	damage_adj = 90;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ������Ϯ��˭��\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		message_vision(HIM"$N���������дʡ�������ʲôҲû�з�����\n"NOR,me);
		return 1;
	}
	

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"qi", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
HIM"\n$N���˼������������˼������ģ����һ�������������ڣ���
����к����ֳ������������͵����Ǳ�����������һ�£������溮�ޱȵ�ˮ������$n\n"NOR,
			//initial message
HIR"\n���$n��ܲ�������ˮ���������ţ�\n"NOR,
			//success message
HIC"\n�����$n�㿪�ˡ�\n"NOR,
			//fail message
HIR"��ˮ�Ʊ�$n�Է�������������$N��ȥ��\n" NOR,
			//backfire initial message
HIR"\n���$n��ܲ�������ˮ���������ţ�\n"NOR,
			//backfire hit message. note here $N and $n!!!
	);

    //me->start_busy(3+random(2));
    me->start_busy(1+random(2));
	return 3+random(5);
}

