//��˽ﵷ���wusi-mace.c
//created 5-12-97 pickle
  
/*
��˽ﵷ�    dodge  5    parry  -5    damage  25
ԭ���ؼ��޵�ﵣ�Ϊ�ؼ��洫�ؼ��������������������
���ƹٱ������ϸ�����˽��������˽ﵷ�����ﵷ��൱ʵ
�ã�����ɱ�У���������
*/

// Ż�ģ���Ѫ�����磬׽Ӱ��
// ׷�꣬������ɱ�֣����顣

inherit SKILL;

mapping *action = ({
  ([
    "name":		"Ż���",
    "action":
"$Nͦ������$w����$n��ǰ���Ͳ���ȥ�����С�Ż��ﵡ����޻��ɣ�����������",
    "dodge":		5,
    "parry":		-5,
    "damage":		35,
    "damage_type":  "����"
   ]),
  ([
    "name":		"��Ѫ�",
    "action":
"$N����$w����$n�ĺ������ҡ����С���Ѫﵡ����Ǵ����ˣ�$n����ŻѪ����",
    "dodge":		15,
    "parry":		-10,
    "damage":		30,
    "damage_type":  "����"
   ]),
  ([
    "name":		"�����",
    "action":
"$N�����Ṧ��$n��Χ����תȦ�����ϵ��·�����������硣\n"
"����$n�ۻ�����֮�ʣ�$Nͦ������$w��$n��$l��ȥ",
    "dodge":		-10,
    "parry":		0,
    "damage":		15,
    "damage_type":  "����"
   ]),
  ([
    "name":		"׽Ӱ�",
    "action":
"$N����$n��������Ӱ��һ�㣬�ﵲ���$n���ġ�\n"
"���ơ�׽Ӱﵡ���Ȼ��$n�Ƶ���æ����",
    "dodge":		5,
    "parry":		-5,
    "damage":		20,
    "damage_type":  "����"
   ]),   
  ([
    "name":		"׷���",
    "action":
"$N��������һ���޺𣬾���$n�����ɢ��\n"
"�ô�������$N����$w��$n��$l����",
    "dodge":		10,
    "parry":		-5,
    "damage":		25,
    "damage_type":  "����"
   ]),   
  ([
    "name":		"�����",
    "action":
"$N����������ǣ��ס$n������$w�͵���$n��ͷ����ɨ��\n"
"�������ơ�����ﵡ���ʵ�ˣ�$n��������֮��",
    "dodge":		5,
    "parry":		-5,
    "damage":		25,
    "damage_type":  "ײ��"
   ]),   
  ([
    "name":		"�����",
    "action":
"$Nս���������Ի���$w������˷�����һﵡ�\n"
"���С�����ﵡ�ʹ���������֮�ڣ����۵��ѣ����������ھ�����",
    "dodge":		5,
    "parry":		5,
    "damage":		15,
    "damage_type":  "����"
   ]),   
  ([
    "name":		"ɱ���",
    "action":
"$NԾ�����ߣ��Ӹ����£�һ���$n��ͷ���¡�\n"
"���С�ɱ��ﵡ������ؼ���˽��еľ��У���Ȼ��������",
    "dodge":		5,
    "parry":		-15,
    "damage":		35,
    "damage_type":  "����"
   ]),
});


int valid_learn(object me)
{
  object ob;
  
  if( (int)me->query("max_force") < 150 )
    return notify_fail("�����������������ѧ��˽ﵷ��� ����Щ���������ɡ�\n");
  if (!(ob = me->query_temp("weapon"))
      ||      (string)ob->query("skill_type") != "mace" )
    return notify_fail("���������һ��ﵲ�����ﵷ���\n");
  
  return 1;
}

int practice_skill(object me)
{
  string myforce=me->query_skill_mapped("force");
  if (myforce != "lengquan-force")
    return notify_fail("��˽�����Ͻ�������Ȫ�񹦲ſɷ���������\n");
  if ((int)me->query("kee") < 35)
    return notify_fail("������Ƿ�ѣ�ǿ��ﵷ��к����档\n");
  if ((int)me->query("force") < 5)
    return notify_fail("���������㣬ǿ����˽����߻���ħ��Σ�ա�\n");
  me->receive_damage("kee", 30);
  me->add("force", -5);
  message_vision("$N������������һ����˽ﵷ���\n", me);
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










