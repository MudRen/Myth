//���ٻ��ơ�baihua-zhang.c
// cglaem...12/08/96.
//menpai skill

inherit SKILL;

mapping *action = ({
	([	"action":		"$NǳǳһЦ��һ�С����ڷɻ������Ρ��������޵�����$n��$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		50,
		"damage_type":	"����",
	]),
	([	"action":		"$N����һ�٣��������⡣$n����������\n����$N������ָ��ֱ��$n˫Ŀ�����ǡ��ٻ��ơ�֮ɱ�֡�һ֦���ӳ�ǽ����",
		"dodge":		-10,
		"parry":		-10,
		"force":		120,
		"damage_type":	"����",
                        "weapon":		"������",
	]),
	([	"action":		"ֻ��$N��ȻһЦ��˫�Ʒ��ɣ�һ�С������һ���ӳ�졹�����������",
		"dodge":		-20,
		"parry":		-20,
		"force":		70,
		"damage_type":	"����",
	]),
	([	"action":		"$N����һ�ڣ���Ȼ�������ߣ�����˳��һ�С��ƾ�֦ͷ����������$n��$l��ȥ",
		"dodge":		15,
		"parry":		15,
		"force":		60,
		"damage_type":	"����",
	]),
            ([	"action":		"ֻ��$N˫�����գ���ɫ���أ�һ�С��˻��������޻���ȫ������$n��$l",
		"dodge":		5,
		"parry":		5,
		"force":		80,
		"damage_type":	"����",
	]),
});

int valid_learn(object me)
{
	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("�ٻ�����ֻ��Ů�Ӳ��������书��\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("���ٻ��Ʊ�����֡�\n");
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

	me->receive_damage("sen", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("moon") + "/baihua-zhang/" + func;
}
