
//wuxing-quan.c������ȭ��, weiqi...980213

inherit SKILL;

mapping *action = 
({
	([	"action":
"$Nʹ������ȭ�еġ����־�������������˫ȭ�Ժϣ�\n��Ȼ�ˣ���һ��������������֮�������ڸ�������һ��֮�䣬\n$N����ֻȭͷ�Ѿ��ҵ���$n��$l",
		"dodge":		5,
		"parry":		5,
		"force":		110,
		"damage_type":		"����"
	]),
	([	"action":
"ֻ��$N�Ų���ò���������һ���ٻΣ�˫ȭ����$n֮���أ�ʹ��$n$l��\n�˴�����ȭ�еġ�ˮ�־����޿ײ��룬ȷ�������鴫",
		"dodge":		5,
		"parry":		5,
		"force":		80,
		"damage_type":		"����"
	]),
	([	"action":
"$Nʹ����ľ�־�����һʱ�����ǽŲ����ͣ�����Ӳ���������һ����\n����һ����ǹ�������̬��������$n��˫�ֳ�צһǰһ��ץ��$n$l",
		"dodge":		5,
		"parry":		5,
		"force":		60,
		"damage_type":		"ץ��"
	]),
	([	"action":
"$N˫ȭ������������ת������һȭֱ�ӻ���$n������ȭ�еġ����־���\nȴ��$N��ȭ�Ʒ��ӵ����쾡�£������ľ��������һ��һ����һ�����������",
		"dodge":		5,
		"parry":		5,
		"force":		60,
		"damage_type":		"����"
	]),
	([	"action":
"$N����������˫�ȱ��ƶ��ڵ���һ�㣬����������ֱȭһ������$n$l��\n����ȭ�еġ����־����Ȳ�����಻���գ�ȴ��һ��������еĺ���",
		"dodge":		5,
		"parry":		5,
		"force":		80,
		"damage_type":		"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ȭ������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
