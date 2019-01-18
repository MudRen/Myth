// ���ױ޷���jinglei-mace.c
// created 5-19-97 pickle

/*
���ױ޷�    dodge  -5    parry  -5    damage  25
�˱޷�(Ӳ�ޣ���ʵ����ﵷ�)�����������ȣ�Ϊ����ξ
�ٹ�֮���־�����ʹ�������������ݣ����ѽ��ˡ�
*/

// ������գ��������أ��������ף�
// �����ܲ��������������˷����꣬
// ������꣬�칫���ᣬ��������

inherit SKILL;

mapping *action = ({
	([	"name":			"�������",
		"action":
"$N���δٽ�������$w����һ�󾢷磬��$n��ͷɨȥ",
		"dodge":		-5,
		"parry":		5,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N����һ�����������α������ƺ�˲Ϣ�䳤����һ��ͷ���������֮�ƣ�\n"
"$N����$wһ�С��������ء�����$n��ͷ���Ե���ȥ",
		"dodge":		-5,
		"parry":		-15,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N���˵��һ��ŭ�𣬺���ƽ�����˸����ף����$n��������ֱ�졣\n"
"�ô�������$N��������$w������$n��$l",
		"dodge":		-15,
		"parry":		-5,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"�����ܲ�",
		"action":
"$N��$w��÷��겻͸��������$n��ȥ��\n"
"$nֻ��һ�ź�Ӱ���Լ�������ʵ�ڲ�֪����м�",
		"dodge":		10,
		"parry":		-10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N��$w���˸�ԲȦ�������������֮���������������֮����\n"
"ͻȻ�䣬ֻ��һ������������$w�ѵ�$n�ʺ���һ�С�����������",
		"dodge":		-10,
		"parry":		0,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"�˷�����",
		"action":
"$N��һ�С��˷����꡹������Χ$n���ܼ�ת��\n"
"������ֻ������˷������Ӱ���ƺ��ѽ�$n������·",
		"dodge":		-5,
		"parry":		-5,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":			"�������",
		"action":
"$N��������а��˿����������Σ������$w���ƿ����������$n",
		"dodge":		-10,
		"parry":		5,
		"damage":		30,
		"damage_type":		"����"
	]),
	([	"name":			"�칫����",
		"action":
"��ս��ֻ��һ����Ӱ������ȥ��$nһ㶣����������Ӱ����ͷ�ҵ���\n"
"$N�ġ��칫���᡹�õ�ǡ���ô����˵��ǹ���Ī��",
		"dodge":		0,
		"parry":		-15,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$Nͦ��$w��$n��$l������ȥ����Ȼ��Ϲ�����������\n"
"ͻȻ�䣬$wһ��Ϊ������$n����������ͬ�Ĳ�λ�ɴ̣�\n"
"$n�����С������������Ƶ��������ˣ���ͼ�㿪$N��׷��",
		"dodge":		-5,
		"parry":		-5,
		"damage":		25,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("���������Ϊ���������ѧ���ױ޷���\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "mace" )
		return notify_fail("����û�б�����ô����\n");
	return 1;
}
	
int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ�����ױ޷��к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ�����ױ޷����߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("ֻ��һ�ź�Ӱ���߳�$N��ԭ�������꾪�ױ޷���\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="mace"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
