// cloudstaff.c
//old es2 skill, not used...

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С����է�֡�������$wɨ��$n���̣�",
		"damage":		20,
		"dodge":		0,
		"parry":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w��һ�С������硹����$n$l��",
		"damage":		20,
		"dodge":		0,
		"parry":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N�������$w��ʹ��������д�⡹����$n$l��",
		"damage":		20,
		"dodge":		0,
		"parry":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��һ�С��������ơ���$wһͦײ��$n$l��",
		"damage":		20,
		"dodge":		0,
		"parry":		0,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 )
		return notify_fail("���������������Ҳ�����һ����������ǿ������\n");

	return 1;
}

int valid_enable(string usage)
{
	return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "staff" )
		return notify_fail("���������һ��ľ�Ȼ��������Ƶ��������������ȷ���\n");

	if( (int)me->query("kee") < 60 )
		return notify_fail("������������������ȷ�����������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 60);
	return 1;
}
