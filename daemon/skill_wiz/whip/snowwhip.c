// former snowwhip.c or es2
// modified to use

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"��������",
		"action":		"$Nʹһ�С��������⡹������$w���ñ�ֱ��$n��$l��������",
		"dodge":		-10,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"name":			"�����ѩ",
		"action":		"$N����һת��һ�С�«�����졹$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"name":			"ѩ������",
		"action":		"$N����$w��һ�С�«��Ʈ�㡹����ӰƮ�������ص���$n��$l",
		"dodge":		-20,
		"damage":		25,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("�������������û�а취����ѩ�޷�, ����Щ���������ɡ�\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

	return 1;
}

int valid_enable(string usage)
{
    return usage == "whip" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("�����������������û�а취��ϰ��ѩ�޷���\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�㰴����ѧ����һ�麮ѩ�޷���\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

