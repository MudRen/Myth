// bighammer.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

//	success_adj = 150;
//	damage_adj = 140;
        success_adj = 170;
        damage_adj = 170;// xintai 1/29/2001 �������������bighammerҲ̫NB��һ��:)
 

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ�ô�����ħ�ƴ�˭��\n");

        if(!metep(me) && me->query("family/family_name")!="�Ϻ�����ɽ")
                return notify_fail("���Ƿ��ŵ��Ӳ����á�������ħ�ơ���\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("���޷����о������������Լ��ˣ�\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("����û��Ӧ������һ�ΰɣ�\n");
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
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N�������˼������ģ�������ֳ����У���Ҷ�����ߣ�������ִ\nһ���޴��ޱȵĽ�ħ�ƣ�������һ����$n��ͷ���£�\n" NOR,
			//initial message
		HIC "����Ҹ����ţ����û��$n�ұ⣡\n" NOR, 
			//success message
		HIC "����$n��ǧ��һ��֮�ʶ��˿�����\n" NOR, 
			//fail message
		HIC "���ǽ�ħ�Ʊ�$n�Է���һ���������ҵ���$N�Ķ��ţ�\n" NOR, 
			//backfire initial message
		HIC "����Ҹ����ţ����û��$n�ұ⣡\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

