// fonxansword.c
//not used yet...

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С����·ת��������$w��һ�����߰����$n��$l",
		"dodge":		0,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ����ɽ�����еġ���ɽ������������ն��$n��$l",
		"dodge":		0,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
		"dodge":		0,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�й�ֱ����һʽ�����ն�������׼$n��$l�̳�һ��",
		"dodge":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
		"dodge":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$wƾ��һָ��һ�С�ͯ����·������$n��$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
		"dodge":		0,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�ὣ��ǰ������һת����$wʹһ�С��չ���硹����һ���⻡ն��$n��$l",
		"dodge":		0,
		"damage":		10,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����ɽ������\n");

	if( (string)me->query_skill_mapped("force")!= "fonxanforce")
		return notify_fail("��ɽ����������Ϸ�ɽ���ڹ���������\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ��ɽ������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ���ɽ������\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("swordsman") + "/fonxansword/" + action;
}
