//qianjun-bang.c ��ǧ��������

/*
ǧ����    dodge  10    parry  -10    damage  30
��������ǧ����������������ﰣ������˵��Ϊǧ����
�����˻������󿪴�ϣ����ư��硣
*/

inherit SKILL;

mapping *action = ({
        ([      "name":                 "�������޸�",
                "action":
"$N�������ˣ�����$wӭ��һ��������$n��ͷ�������ҽ�����",
                "dodge":                5,
		"parry":	-10,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "̸Ц�����",
                "action":
"$N���쳤Ц����Ҳ������һ�С�̸Ц�������������һ����$n��ͷ����",
                "dodge":                0,
		"parry":		0,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�¶�������",
                "action":
"$Nһ��������Խ��$nͷ��������$w�ո���Բ��������һ������$n$l",
                "dodge":                10,
		"parry":	-20,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����Ͼ�¯",
                "action":
"$Nһ���޺ȣ���һ���������Ͼ�¯����\n����$nһ�֮�䣬$N����$w���Ǻ�Х������ɨ��$n��$l",
                "dodge":               10,
		"parry":	-15,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������һ�",
                "action":
"$Nʹ����������һ᡹���Ų����ԣ���һ������һ����\n���$n��æ���ң��мܲ���",
                "dodge":                -5,
		"parry":		-5,
                "damage":               30,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "����׹Ǿ�",
                "action":
"$N����������ƣ�����$wת����糵һ�㣬\nһ�������Ӱ���л���$n����",
                "dodge":                5,
		"parry":	-10,
                "damage":               20,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "ǧ��������",
                "action":
"$N����$wһ������Ϊǧ���ϼ�⣬\n����$nĿѣ��ҡ֮ʱ����һ����ϼ����գ�\n$w�ѵ���$n��$l����һ���и����ã�������ǧ�������",
                "dodge":                0,
		"parry":	-20,
                "damage":               40,
                "damage_type":  "����"
        ]),
	([	"name":			"Ǭ��һ��",
		"action":	"$N������$wӭ��һ�ӣ��ó���ǧ��Ӱ�������������߾ٹ�����
$w��׼$n�����ž�������ȥ����һ��Ҫ�Ǵ��У����������޽���Ҳ����һ��",
		"parry":	-30,
		"dodge":	-50,
		"damage":	100,
		"damage_type":  "����"
	]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취��ǧ��������
����Щ���������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�����������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query_temp("QJB_perform");
	if( !me->query_temp("QJB_perform")) {
		return action[random(7)];
	}else {
		return action[i];
	}
//        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰǧ��������\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        write("�㰴����ѧ����һ��ǧ��������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("puti") + "/qianjun-bang/" + func;
}

