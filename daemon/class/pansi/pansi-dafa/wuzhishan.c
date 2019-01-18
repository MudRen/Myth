// wuzhishan.c,��ָɽ
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ����ָɽ��˭��\n");

        if (!PFM_D->valid_family(me, "��˿��"))
                          return notify_fail("����ָɽ��ֻ����˿�����˲ſ����ã�\n");

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
		HIC "$N�������˼������ģ�����г���һ����ָɽ��������һ����$n��ͷ���£�\n" NOR,
			//initial message
		HIC "����Ҹ����ţ����û��$nѹ�⣡\n" NOR, 
			//success message
		HIC "����$n��ǧ��һ��֮�����˿�����\n" NOR, 
			//fail message
		HIC "������ָɽ��$n�Է���һ���������ҵ���$N�Ķ��ţ�\n" NOR, 
			//backfire initial message
		HIC "����Ҹ����ţ����û��$nѹ�⣡\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

