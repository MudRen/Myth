//modified by vikee
//2000.10

inherit SKILL;

mapping *action = ({
		([	"name":			"��������",
		"action":
"$N˫��һ�٣���ֱԾ������$w��ͣ�ز����ţ�\n"
"����ס$nȫ�����ơ��������硹��Ȼ���޿ײ���",
		"dodge":		-5,
		"parry":		-10,
		"damage":		 25,
		"damage_type":		"����"
	]),
	([	"name":			"�������",
		"action":
"$N����$w�����㺮�⣬ָ��$nǰ��Ѩ����$n��ר����־�ضԸ��Ž��У�\n"
"����$N������������$n��$l�����ơ�������硹������ã�ʵ���ѷ�",
		"dodge":		-5,
		"parry":		15,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N��$n�������ߣ�һ��[��������],����$wȥ��Ʈ��������ֻ����$n�ۻ����ҡ�\n"
"�ô�������$N������������һ��$w����$n��$l����",
		"dodge":		-15,
		"parry":		10,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"�����п�",
		"action":
"$N��������$w��������㺮�⣬��ס$n���ظ���ֻ��$n��������\n"
"���С������пա�ֱ��ϸ�����ܣ�$nʵ�ڲ�֪$w��Ҫָ���Լ����Ϻδ�",
		"dodge":		25,
		"parry":		-10,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"������Ӱ",
		"action":
"$N����$w�й�ֱ�������ٴ���$n��ǰ�ġ�\n"
"���С�������Ӱ�����˶�Ŀһ�¡�$nֻ������һ����$w�Ѵ̵���$l",
		"dodge":		-15,
		"parry":		15,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N����$w��$n�����ּ��̣�������$nҪ�м�ʱ��\n"
"$wȴͻȻת����$n�����㣡���С��������ڡ�ȷʵ���Ī��",
		"dodge":		10,
		"parry":		-15,
		"damage":		25,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("���������Ϊ�����������ѧ��Ҳû�á�\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ������\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ���������к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ�����������߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NĬĬ������һ�����Ȼ������һ����������\n", me);
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
	return CLASS_D("shushan") + "/yujianshu/"+func;
}
