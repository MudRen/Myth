// jadesword. ����ħ������
// edited 4-16-97 pickle

/*
���޽���    dodge  5    parry  -10    damage  25
���޽���Ϊƴ��������ֻ���˵У���������Σ������
ͻ��֮����ǿ��Ȼ�������Ҵ�һ���������Ӷ�������
*/

// �����ʬ�����ײ��ϣ��������̣�
// �˷����꣬����һ����ʮ�����

inherit SKILL;
void set_busy();
mapping *action = ({
    ([
      "action":
"$N����һ����$w���⻯Ϊ����׹⣬�ֱ���$n���ʺ����Ҽ硢�����ҽ��󼲴�",
      "dodge":		0,
      "parry":	        0,
      "damage":		20,
      "damage_type":	"����",
      "name":		"�������ʬ��",
      ]),
    ([
      "action":
"$N�ؽڽ�Ӳ������$w��һ������һ�������ɨ��\n"
"$nʶ�����С����ײ��ϡ�����������æ��ܲ���",
      "dodge":		10,
      "parry":		-20,
      "damage":		30,
      "damage_type":	"����",
      "name":		"�����ײ��ϡ�",
      ]),
    ([
      "action":
"$N����Ծ������$w����������⣬��$n�����ŵ�ȥ��\n"
"���С��������̡���Ȼ��$n�Ƶ���æ����",
      "dodge":		5,
      "parry":	       -10,
      "damage":		20,
      "damage_type":	"����",
      "name": 		"���������̡�",
      "post_action":	(:set_busy:),
      ]),
	
    ([
      "action":
"$N�ܲ���������$w���籩�����$n������\n"
"���С��˷����꡹��Ȼ¶�����ɿ��ţ���$nҲ���Ҳ�������Σ��óȻ����",
      "dodge":		5,
      "parry":	        -5,
      "damage":		30,
      "damage_type":	"����",
      "name": 		"���˷����꡹",
      "post_action":	(:set_busy:),
      ]),
    ([
      "action":
"$N���˴���������$n��$l���������С�����һ����
������$n��$N���˾Ϳ��Ŵ󿪣������׸���",
      "dodge":		10,
      "parry":	        -10,
      "damage":		35,
      "damage_type":	"����",
      "name": 		"������һ����",
      "post_action":	(:set_busy:),
      ]),
    ([
      "action":
"$N���潣�ߣ�Ѹ�����׵���$n��Χ��Ȧ��\n"
"$nֻ����Χ������Ӱ����ʱ���п�����һ��$w�����벻����\n"
"λ�ô�����ʵ����Σ������",
      "dodge":	       0,
      "parry":		-15,
      "damage":		15,
      "damage_type":	"����",
      "name": 		"��ʮ�������",
      ]),
});

int valid_learn(object me)
{
    object ob;
    
    if ((int)me->query("max_force") < 100)
	return notify_fail("����������㣬�������򽣷��ľ���֮����\n");
    
    if (!(ob = me->query_temp("weapon"))
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
    if ((int)me->query("kee") < 30)
	return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
    if ((int)me->query("force") < 5)
	return notify_fail("�������������û�а취������ħ������\n");
    me->receive_damage("kee", 30);
	me->add("force", -5);
    write("�㰴����ѧ����һ����ħ������\n");
    return 1;
}
void set_busy()
{
    object me=this_player();
    me->start_busy(1);
}
