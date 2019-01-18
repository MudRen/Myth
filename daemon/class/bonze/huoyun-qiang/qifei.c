// ǹ�����

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void check_fight(object me, object target, object victim, int amount);
int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object weapon, victim = offensive_target(me);

	if (!victim) return notify_fail("�����˭���С�ǹ����ɡ���\n");

	if( !target )
		return notify_fail("������˭���С�ǹ����ɡ���\n");
	if( target->query("id") == me->query("id") )
		return notify_fail("�������Լ����С�ǹ����ɡ���\n");
	if( victim->query("id") == target->query("id") )
		return notify_fail("��������Ķ��ֽ��С�ǹ����ɡ���\n");
	if( target->query("id") != me->query("bonze/dadangid") 
	 && target->query("id") != me->query("couple/id") )
		return notify_fail("��ֻ�������С�ǹ����ɡ���\n");

	if( !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("ֻ�ܶ�������ս���еĶ���ʹ�á�ǹ����ɡ���\n");
	if( !target->is_fighting(victim) )
		return notify_fail("��Ĵ���������ս���С�\n");
	if( !objectp(weapon=target->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "staff" &&
		weapon->query("skill_type") != "staff" ) || 
		target->query_skill_mapped("staff") !="lunhui-zhang" )
		return notify_fail("��Ĵû����ʹ���ֻ��ȡ�\n");
	if( (int)target->query_temp("qifei") )
		return notify_fail("��Ĵ�Ѿ���ʹ�á�ǹ����ɡ��ˡ�\n");
	if( (int)me->query_temp("qifei") )
		return notify_fail("���Ѿ���ʹ�á�ǹ����ɡ��ˡ�\n");
	if((int)me->query("force") < 25+(int)me->query("force_factor") )
		return notify_fail("�������������\n");
	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
	if((int)target->query("force") < 25+(int)me->query("force_factor") )
		return notify_fail("��Ĵ����������\n");
	if((int)target->query("kee") < 100 )
		return notify_fail("��Ĵ��Ѫ���㣬û����ʩ���⹦��\n");

	if( !(int)target->query_temp("qifei_request") ) {
		me->set_temp("qifei_request", 1);
		tell_object(target, me->query("name")+"���㷢����ǹ����ɡ�����\n");
		return 1;
	}
	target->delete_temp("qifei_request");

	me->add("force", -25-(int)me->query("force_factor"));
	target->add("force", -25-(int)me->query("force_factor"));
	me->receive_damage("kee", 100);
	target->receive_damage("kee", 100);

	skill1 = target->query_skill("lunhui-zhang", 1);
	skill2 = me->query_skill("huoyun-qiang", 1);
	skill = (skill1 + skill2)/2;
	message_vision(HIY
		"$N��$n���б����໥һ������Χ����һƬǹ�����꣬ѹ��"
		+ victim->query("name") + "��������������������ȫ��ʧȥ���·���\n"
		NOR, me, target);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/dodge",  skill);
	me->set_temp("qifei", 1);
	target->add_temp("apply/attack", skill);
	target->add_temp("apply/dodge",  skill);
	target->set_temp("qifei", 1);

//	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill :), 1);
	call_out("check_fight", 1, me, target, victim, skill);

	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ) 
		remove_effect(me, target, amount);

	else if(   !present(victim->query("id"), environment(me)) 
		|| !target->is_fighting(victim)
		|| !present(target->query("id"), environment(me)) 
		|| !me->is_fighting(victim) ) 
		remove_effect(me, target, amount);

	else if( !objectp(weapon=me->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "spear" &&
		weapon->query("skill_type") != "spear" ) || 
		me->query_skill_mapped("spear") != "huoyun-qiang" )
		remove_effect(me, target, amount);

	else if( !objectp(weapon=target->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "staff" &&
		weapon->query("skill_type") != "staff" ) || 
		target->query_skill_mapped("staff") != "lunhui-zhang" )
		remove_effect(me, target, amount);

	else call_out("check_fight", 1, me, target, victim, amount);
}

int remove_effect(object me, object target, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", -amount);
	target->add_temp("apply/attack", -amount);
	target->add_temp("apply/dodge", -amount);
	me->delete_temp("qifei");
	target->delete_temp("qifei");
	message_vision(GRN"$N��$n�ġ�ǹ����ɡ���ʽһ�գ���һ���ŵ�ɱ����ʱ��ʧ����Χ����Ҳ������һ������\n"NOR, me, target);
	return 0;
}

