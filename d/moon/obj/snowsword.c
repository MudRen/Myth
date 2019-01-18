// snowsword. ��ѩɽ������

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С�ɽ�����ߡ�������$w��Ϊһ���������$n��$l",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"ֻ��$N������ת��ʹ���������ƺ�����һ����Ц�н���������ɨ��$n��$l",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"ֻ��$N������������$w���й�ֱ��������$n��$l����һ�С���Խǧɽ�����������ƷǷ�",
		"dodge":		-30,
		"damage":		25,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w����һ����һʽ��ǧ����⡹�ó�һ�麮������$n��$nֻ����������������ס��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w��һ����ֻ�������㣬Ʈ��������\n��һ�С�����ѩƮ��ֻ����$n�ۻ����ң����ﻹ���м�",
		"dodge":		-20,
		"damage_type":	"����"
	]),
	
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취��ѩɽ������\n");

	if( (string)me->query_skill_mapped("force")!= "moonforce")
		return notify_fail("ѩɽ���������������ɽ��Ů���Բ���ķ���������\n");

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
		return notify_fail("�����������������û�а취��ϰѩɽ������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ��ѩɽ������\n");
	return 1;
}
