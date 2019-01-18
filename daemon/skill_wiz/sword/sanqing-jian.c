
// sanqing-jian.c�����彣����
//for ��ʿ NPCs, if going to be used by players, need refine. 

/*
���彣��    dodge  -5    parry  15    damage  20
���ҹ�������Ʈ�ݣ���մ����֮������Ψ��̫������
����̫ʵ�á�
*/

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹ��һ�С��Ǻ�Ӱ������������˸�������������޵ش���$n$l",
		"dodge":		0,
		"parry":		15,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":		"$N����ת����ͣ��ͻȻһ�С�һ����Ϭ��ʹ��������$w����һ������������$n$l",
		"dodge":		-10,
		"parry":		15,
		"damage":		25,
		"damage_type":	"����"
	]),
	([	"action":		"$N����̤�˸����ǲ���һ�С��ŵ����硹����$w����������$n����һն",
		"dodge":		-5,
		"parry":		15,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"����$N���˼�������Ȼ������Ծ������$wһʽ���׺���������׼$n��$l���һն",
		"dodge":		-15,
		"parry":		5,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һԾ��ʹ�˸����˷��ȥ����ȴ��ת��֮�ʶ�׼$n$lбб�ӳ�һ��",
		"dodge":		5,
		"parry":		25,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":		"$N��̬���У�����$wƾ��һָ��һ�С�����ǧ�ء�����ػ���$n��$l",
		"dodge":		-10,
		"parry":		10,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w����һ�֣�ʹһ�С�����ͨ�ġ����ֶ�׼$n$lһ����ȥ",
		"dodge":		0,
		"parry":		20,
		"damage":		15,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����彣����\n");

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
		return notify_fail("�����������������û�а취��ϰ���彣����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ�����彣����\n");
	return 1;
}

