inherit SKILL;
void set_busy();
mapping *action = ({
  ([
        "action" : "$Nһ�С���÷��Թ����˫�ֺ�ӣ�ץ��$n",
        "dodge" : 20,
        "parry" : 10,
        "damage" : 10,
        "damage_type" : "����" ,        "name" : "����÷��Թ��",
  ]),
  ([
        "action" : "$Nһ�С��ƻ���Գ������ԾȻ����ץ��$n��ͷ��",
        "dodge" : 20,
        "parry" : 10,
        "damage" : 20,
        "damage_type" : "����" ,        "name" : "���ƻ���Գ",
  ]),
  ([
        "action" : "$Nһ�С���ɽһ�����ı̡���˫�ַ׷ɣ�$nֻ���ۻ�����",
        "dodge" : 30,
        "parry" : 10,
        "damage" : 30,
        "damage_type" : "����" ,        "name" : "����ɽһ�����ı̡�",
  ]),
  ([
        "action" : "$Nһ�С�÷��ѩ�串��ƻ����˫�ֺϻ���$nֻ���޴��ɱ�",
        "dodge" : 30,
        "parry" : 10,
        "damage" : 45,
        "damage_type" : "����" ,        "name" : "��÷��ѩ�串��ƻ��",
  ]),
  ([
        "action" : "$Nһ�С�������÷��ѩ�ҡ���˫��ƮȻץ��$n",
        "dodge" : 30,
        "parry" : 10,
        "damage" : 50,
        "damage_type" : "����" ,        "name" : "��������÷��ѩ�ҡ�",
  ]),
  ([
        "action" : "$N˫��ƽ�٣�һ�С�����������ŪӰ������$n",
        "dodge" : 35,
        "parry" : 10,
        "damage" : 80,
        "damage_type" : "����" ,        "name" : "������������ŪӰ��",
  ]),
  ([
        "action" :    "$Nһ�С���������ֱ���ۡ�������$n���ƺ�$n��ȫ��������",
        "dodge" : 30,
        "parry" : 10,
        "damage" : 100,
        "damage_type" : "����",
        "name" : "����������ֱ���ۡ�",
  ]),
  ([
        "action" : "$N������Σ�����һ�ǡ�����δ�϶��Ⱦ�������$n��ͷ��",
        "dodge" : 30,
        "parry" : 10,
        "damage" : 150,
        "damage_type" : "����" ,        "name" : "������δ�϶��Ⱦ���",
  ]),
  ([
        "action" : "$Nʩ��������Ц�졹�����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
        "dodge" : -10,
        "parry" : 10,
        "damage" : 150,
        "damage_type" : "����" ,        "name" : "������Ц�졹",
  ]),
  ([
        "action" : "$Nʩ������ʯ��١�������һ������$n",
        "dodge" : -20,
        "parry" : 10,
        "damage" : 150,
        "damage_type" : "����",
        "name" : "����ʯ��١�",
  ])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry";}

int valid_learn(object me)
{
        if (me->query_temp("weapon"))
                return notify_fail("��ժ���ֱ�����֡�\n");
        if ((int)me->query("max_force") < 50)
                return notify_fail("�������̫�����޷���ժ���֡�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 20)
                return notify_fail("�������������ժ���֡�\n");
        me->receive_damage("kee", 25);
        me->add("force", -10);
        write("�㰴ʦ����������һ��ժ���֡�\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhenwu") + "/zhaixing-shou/" + action;
}

