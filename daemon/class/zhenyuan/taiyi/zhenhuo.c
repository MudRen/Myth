//zhenhuo.c ��̫�����weiqi...980305

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

        success_adj = 110;
        damage_adj = 100;

	if( !target ) target = offensive_target(me);

if (environment(me)->query("no_fight"))  return notify_fail("��ȫ���ڽ�ֹʩչ������\n"); 

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("��Ҫ��˭��̫�����\n");

	if((int)me->query_skill("taiyi", 1) < 50 )
		return notify_fail("���̫���ɷ���򲻹���������ó����\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ��������������������û��ʲô�ã�\n");

	if((int)me->query("force") < 100 )
		return notify_fail("��������������޷�����������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("���������ǲ��壬����Լ������ˣ�\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->add("force", -100);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) 
	{
		write("��һ�κ����顣\n");
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
		HIC "$N����ָͷѸ������ͻȻ����һ�磡��Ȼ��������������һ����$n��ȥ��\n" NOR,
			//initial message
		HIC "���$n���յý�ͷ�ö\n" NOR, 
			//success message
		HIC "����$n����һ���Ͷ��˿�����\n" NOR, 
			//fail message
		HIC "���ǻ��汻$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR, 
			//backfire initial message
		HIC "���̫������ɣ�$n���յý�ͷ�ö\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

