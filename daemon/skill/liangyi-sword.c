// liangyi-sword. �����ǽ�����

/*
���ǽ���    dodge  -10    parry  -10    damage  15
�˽���Ϊ������ʦ����֮ʱżȻ���������ʽ����Ϊ������������������ǿ������ϰ
ʱһ��һʽ����������֮����ϣ����ڹ���Ϊ�����洦��
*/

// �����ã��ƣ������� (dodge: -15, parry: -15, damage 10)
// �������������̣��� (dodge: -5, parry: -5, damage 20)
inherit SKILL;

mapping *action = ({
	([	"name":			"��",
		"action":
"$Nһ�����е�$w��˲��̳���ʮ������$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-10,
                "parry":                -20,
		"damage":		5,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһ������$n��$n��æ���Ա�һ����\n"
"����$Nһ�˾��������е�$wͻȻ���˹�����ת������$n��$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N����$w�������������⻷��һ����������$n��ǰ̤��һ����$N���ֽ�ָ�Ѵ���$n��$l",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһת������$n������$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N�������е�$w�����϶��£�����$n��$l",
		"dodge":		0,
                "parry":                -10,
		"damage":		25,
		"damage_type":		"����"
	]),
        ([      "name":                 "��",
		"action":
"$N����һ�࣬���е�$wƽ�Żӳ�������$n��$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":      		15, 
                "damage_type":  	"����"
        ]),
	([      "name":                 "��",
		"action":
"$N��ǰ̤���벽������$w�й�ֱ��������$n��ǰ��",
                "dodge":                -10,
                "parry":                0,
                "damage":     		20,
                "damage_type":  	"����"
        ]),
	([      "name":                 "��",
                "action":
"$N˫��һ�٣�������գ�ͷ�½��ϣ�����$w����$n��ͷ��",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":  	"����"
        ]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����ǽ�����\n");


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

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
        return CLASS_D("puti") + "/liangyi-sword/" + func;
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ���ǽ�����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
//        write("�㰴����ѧ����һ�����ǽ�����\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
