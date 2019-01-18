//Cracked by Roath
// gouhun.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ���Լ��Ļꣿ\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ��������ˣ�\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("�������Լ��ͻ겻���ᣡ\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("����ǹ�����ˣ�\n");
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
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N��$n������Ц�ţ������������������������㵽���������\n" NOR,
			//initial message
		HIC "$n�ܵ�$NӰ�죬��Ȼ�е�겻�����ˣ�\n" NOR, 
			//success message
		HIC "����$n����רע����$N������\n" NOR, 
			//fail message
		HIC "����$n��һ�ɣ����컯��֮�£����ɶ����У�\n" NOR, 
			//backfire initial message
		HIC "���$n�����е�겻�����ˣ�\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);

}

