//������ָ��puti-zhi.c
// cglaem...12/10/96.
//menpai skill

inherit SKILL;

mapping *action = ({
	([	"action":		"$N��������һָ�������һ�����й�ֱ����\nָδ����ָ���Ѱ�$nѹ�ô���������",
		"dodge":		-5,
		"parry":		-5,
		"force":		60,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action":		"$N���β������������������黨��״��$n��һ��ԥ��$N����ָָ��������$n��$l",
		"dodge":		10,
		"parry":		-10,
		"force":		120,
		"damage_type":	"����",
                        "weapon":		"������ָ",
	]),
	([	"action":		"ֻ��$Nһת��һָ��в�´���������$n��$l",
		"dodge":		-5,
		"parry":		10,
		"force":		80,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action":		"$N˫��һ��ʮָ�紩������һ�����·��ɡ�$nֻ����ȫ����$Nָ������֮��",
		"dodge":		-15,
		"parry":		10,
		"force":		60,
		"damage_type":	"����",
                        "weapon":		"����ʳָ", 
	]),
            ([	"action":		"ֻ��$N���΢Ц�����ֶ���������$n������һ��ָ��ֱ��$l����",
		"dodge":		15,
		"parry":		-5,
		"force":		60,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
            ([	"action":		"����$Nһ����߳�����ֻ��˸��뻡������ʳָ��������$n��$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		70,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ָ������֡�\n");
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

	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);

	return 1;
}

