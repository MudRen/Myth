// sgzl
// ��������������

/*
�ɺ׽���    dodge  -5    parry  -5    damage  25
��ɽ����ɽ����������ʽ��
*/

//����ӭ�͡��ƹȺ׷塡��ɽ������
//�׺�����Я�����ơ���������  

inherit SKILL;


mapping *action = ({
	([	"name":			"����ӭ��",
		"action":
"$N��������,����$w���գ���$n��ȥ�������ƿ�ɽ��һ�㣬��һ�����ۺ�ġ�����ӭ�͡�",
		"dodge":		-10,
		"parry":		20,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"�ƹȺ׷�",
		"action":
"ֻ��$N���ָ�����������轣������$w��$n��ȫ��ȥ\n"
"����һ�С��ƹȺ׷塹��",
		"dodge":		  24,
		"parry":		-19,
		"damage":		  25,
		"damage_type":		"����"
	]),
        ([      "name":                 "��ɽ����",
                "action":
"$N������ǰ������$w���裬һ�С���ɽ�������ó����Ž�â����$n������������",
		    "dodge":		 -15,
                "parry":           -15,
                "damage":          35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�׺�����",
                "action":
"$N���˷��������һ����Х������$w������$n��$l��ȥ������ɽ����Х��ġ��׺�������ȫ��$n������",
                "dodge":                15,
                "parry":                15,
                "damage":               35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "Я������",
                "action":
"ֻ��$N������أ�ʹ��һ�С�Я�����ơ�������$w���ٷɽ���������㽣����ֱ��$n��$l��ȥ",
                "dodge":                -10,
                "parry":                -10,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$N����ǰ����һʽ���������硹�����潣����$nȫ���������â������������������$n�������ܵù�",
		"dodge":	          -15,
		"parry":		15,
		"damage":		20,
		"damage_type":		"����"
	])
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("���������Ϊ������޷�ѧϰ�ɺ׽�����\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ������\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("songhe-sword");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ���ɺ׽����к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ���ɺ׽������߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
//        message_vision("$NĬĬ������һ�����Ȼ������һ���ɺ׽�����\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("shushan") + "/songhe-sword/"+func;
}
��
