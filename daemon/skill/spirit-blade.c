inherit SKILL;

mapping *action = ({
([      "action" : "$N������$wһ�һ�������$n��$l��ȥ",
        "damage" : 180,
        "dodge" : -50,
        "parry" : -30,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��$w��һƬ��ϼ����$n��$l",
        "damage" : 220,
        "dodge" : -80,
        "parry" : -50,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }

int valid_learn(object me)
{
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
                return notify_fail("����������������鵶����\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}


