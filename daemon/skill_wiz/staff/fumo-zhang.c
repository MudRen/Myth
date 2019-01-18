
//����ħ�ȡ�fumo-zhang.c, weiqi...980305
inherit SKILL;

/*
��ħ��    dodge  2.5    parry  -6    damage  23
��ׯ�۹���
*/

mapping *action = ({
	([	"action":		"$N����������$w���˼�����Բ��������һ����$n��ͷ����",
		"dodge":		15,
		"parry":		-5,
		"damage":		35,
		"damage_type":	"����"
	]),
	([	"action":		"ֻ��$Nһ���߽У��������־��ܣ����е�$wһ�ʣ�ɨ��$n$l",
		"dodge":		0,
		"parry":		-15,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��һ�С�Ⱥħ���ס������е�$w������ɳ��ʯ����ȷ�ѹ��$n��$l",
		"dodge":		5,
		"parry":		-5,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"ֻ��$N����һ�ˣ�����һ���粽��$w����һ���������$n$l",
		"dodge":		5,
		"parry":		0,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N���$w��������������Ȼ��ֻ����ͷһ�������߰�����$n��$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$w����һ������;ȴʹ�˸��ɾ�����βಣ���һ��������$n$l",
		"dodge":		-5,
		"parry":		-10,
		"damage":		25,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취ѧ��ħ�ȡ�\n");

	if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
		return notify_fail("���������һ�����Ȳ���ѧ��ħ�ȡ�\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="staff"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
		return notify_fail("������̫���ˣ�ǿ�����档\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�㰴����ѧ����һ���ħ�ȡ�\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

