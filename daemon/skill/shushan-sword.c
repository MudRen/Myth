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
"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
      "dodge":		20,
      "parry":	      -20,
      "damage":		30,
      "damage_type":	"����",
      "name":		"����Ӱ���ϡ�",
      ]),
    ([
      "action":
"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",
      "dodge":		10,
      "parry":		-20,
      "damage":		30,
      "damage_type":	"����",
      "name":		"���Լ�С����",
      ]),
    ([
      "action":
"�����$N�����ϣ��ڵ�$n�������Ծ��ԭ��",
          "dodge":		 -10,
      "parry":	       -10,
      "damage":		  30,
      "damage_type":	"����",
      "name": 		"�������ϡ�",
      "post_action":	(:set_busy:),
      ]),
	
    ([
      "action":
"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������",
      "dodge":		    20,
      "parry":	        -20,
      "damage":		   30,
      "damage_type":	"����",
      "name": 		"���з�һ�䡹",
      "post_action":	(:set_busy:),
      ]),
    ([
      "action":
"$Nһ����Ц������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
      "dodge":		    -10,
      "parry":	        -10,
      "damage":		    35,
      "damage_type":	"����",
      "name": 		"��������ǰ��",
      "post_action":	(:set_busy:),
      ]),
    ([
      "action":
"$N����Ծ��$ņ��һ����������$N����ֱ����£�����$w����$n��$l",
      "dodge":	       20,
      "parry":	           -15,
      "damage":		30,
      "damage_type":	"����",
      "name": 		"������Ծ��",
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
	return notify_fail("�������������û�а취������ɽ������\n");
    me->receive_damage("kee", 30);
	me->add("force", -5);
    write("�㰴����ѧ����һ����ɽ������\n");
    return 1;
}
void set_busy()
{
    object me=this_player();
    me->start_busy(1);
}
