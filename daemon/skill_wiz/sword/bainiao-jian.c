// sgzl
// ���񽣷���

/*
���񽣷�    dodge  -5    parry  -5    damage  20
ѩɽ�ɸ���ģ�°��ݲ����Ķ�������
*/

// ����չ��,ӥ������,�������,�ۼ�����,�����ƶ�,�������
// �ž���Ѫ,���ﱨ��,��Ӱ����,��ȸ����,����ѧ��,ԧ��Ϸˮ

inherit SKILL;


mapping *action = ({
	([	"name":			"����չ��",
		"action":
"$N����$w�󿪴��أ�ÿһ����$n��ȥ�������ƿ�ɽ��һ�㣬��һ���Ƶ��۵ġ�����չ�᡹",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"ӥ������",
		"action":
"ֻ��$N�������ˣ�������ббԾ������$w��ֱ����$n��$l��ȥ\n"
"����һ�С�ӥ�����ա���",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"����"
	]),
        ([      "name":                 "�������",
                "action":
"$N������ǰ������$w���裬һ�С�������졹�ó����Ž�â����$n������������",
		"dodge":		-10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�ۼ�����",
                "action":
"$N���˷��������һ����Х������$w�������ֱָ$n��$l������ɽ����Х��ġ��ۼ���������ȫ��$n������",
                "dodge":                -10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�����ƶ�",
                "action":
"ֻ��$N�����أ�ʹ��һ�С������ƶˡ�������$w�������ó���㺮�ǣ�ֱ��$n��$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�������",
                "action":
"$N��ȻԾ��һʽ��������⡹�����潣����$n���ļ������������������������꣬$n�������ܵù�",
		"dodge":		-5,
		"parry":		-5,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"�ž���Ѫ",
		"action":
"$N�������Ž��������ֽ���ס������һʽ���ž���Ѫ��������$wƽƽ�̳���\n"
"���⼱����������֪����δ�",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"���ﱨ��",
		"action":
"$N��һ���������������߽���һ������һ����һʽ�����ﱨ��������������Ʈ�ݣ���������Ĺ���$n��$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":			"��Ӱ����",
		"action":
"ֻ��$N����ƽƽ����������Ȼ�������������$wһ����\n"
"һ�����罫$n�����������У�$wֱ��$n��$l����һ�С���Ӱ��������Ȼ��ʫ�续",
		"dodge":		-20,
		"parry":		10,
		"damage":		20,
		"damage_type":		"����"
	]),
        ([      "name":                 "��ȸ����",
                "action":
"ֻ��$N���ʮ���佣��������ʮ������ʽ��罫$n�������У�$n����ʶ�����С���ȸ������������",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ѧ��",
                "action":
"$NͻȻ��ɫͻ�䣬���黬�������б����$n����ʽһģһ����ȴ�ִ�����ס������з���\n"
"�ۼ�$N$wֱ��$n��$l��$nȴ��֪��η������С�����ѧ�ࡹ",
                "dodge":                -5,
                "parry":                0,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "ԧ��Ϸˮ",
                "action":
"$N����΢�ڣ��������̣���һ�С�ԧ��Ϸˮ��ȥ�ƹ�Ȼ���������ҷ��˴�Լ��ֱ��$n��$l",
                "dodge":                -10,
                "damage":               25,
                "damage_type":          "����"
        ]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("���������Ϊ������޷�ѧϰ���񽣷���\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ������\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("bainiao-jian");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ�����񽣷��к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ�����񽣷����߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NĬĬ������һ�����Ȼ������һ����񽣷���\n", me);
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
��
