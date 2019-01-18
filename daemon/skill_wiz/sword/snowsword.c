// snowsword. �����ѩ�轣����

/*
���ѩ�轣��    dodge  -20    parry  -10    damage  15
�˽���Ѹ������أ�������ѩ�裬���ּ��Ѷ����мܣ���Ϊ
��������֮Ů����ϲ��
*/

// �������ջ�Ӧפ����������ƽɳ
// �ܻ�Ⱦ����˪�ۣ�˪ӡ������Ҳ��
// ��ɸ���������磬���㸡��Ӱ�ƻ�
// �粨������֦��
inherit SKILL;

mapping *action = ({
	([	"action":
"$Nʹһ�С��������ջ�Ӧפ��������$w��Ϊһ���������$n��$l",
		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"����"
	]),
	([	"action":
"ֻ��$N������ת��ʹ������������ƽɳ����һ�������н���������ɨ��$n��$l",
		"dodge":		-35,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":
"$N����һЦ��һʽ���ܻ�Ⱦ����˪�ۡ����������Ӱ��$nֻ����������������Ϯ����ȴ��֪���������",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"$N����$w����һ����һʽ��˪ӡ������Ҳ�ա��ó�һ�麮������$n��$nֻ����������������ס��",
		"dodge":		-30,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"$N����$w��һ����ֻ�������㣬Ʈ��������\n��һ�С���ɸ���������硹ֻ����$n�ۻ����ң����ﻹ���м�",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"����"
	]),
        ([      "action":
"$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n��󣬽���ֱָ$n�ĺ��أ�����һʽ�����㸡���»ƻ衹",  
                "dodge":                -35,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "����"
        ]),
	([      "action":
"$N�������ܣ�һʽ���粨������֦��������ɫ��ţ����ƴ�����һ��������ˮ�����������Ľ���ֱָ$n��������",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "����"
        ]),
	
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����ѩ�轣����\n");

	if( (string)me->query_skill_mapped("force")!= "moonforce")
		return notify_fail("���ѩ�轣�������������ɽ��Ů���Բ���ķ���������\n");

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
		return notify_fail("�����������������û�а취��ϰ���ѩ�轣����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ����ѩ�轣����\n");
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("moon") + "/snowsword/" + func;
}

