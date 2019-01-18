//Cracked by Roath

// hunyuan-zhang.c ��Ԫ��

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ�����Ƴ�ᶡ���˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
        "force" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N��ָ�罣��һʽ���׺���ա�������$n��$l��ȥ",
        "force" : 80,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ���ƶ����롹������΢��������է��է�ϣ��͵ز���$n��$l",
        "force" : 90,
        "damage_type" : "����"
]),
([      "action" : "$N˫����������������һʽ�����ɴ�䡹���ó�������̵����룬������$n��ȥ",
        "force" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N��������һ�ݣ�ʹ��һʽ������������˫�Ʋ�£����ֱ����$n��$l��ȥ",
        "force" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N����һ�䣬ʹһʽ���ޱ���ľ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
        "force" : 80,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ����ɽ��ˮ�����������أ�������ӯ��ͬʱ��$n��$l��ȥ",
        "force" : 120,
        "damage_type" : "����"
]),
([      "action" : "$Nͻ��һ�С��������á���˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
        "force" : 100,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��������ơ���˫�������һ����裬�����ѻ���$n��$l��",
        "force" : 110,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ������Ʈ�졹����������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
        "force" : 80,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" ; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ԫ�Ʊ�����֡�\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��Ԫ�ơ�\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷�����Ԫ�ơ�\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 40)
                return notify_fail("���������������Ԫ�ơ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") +"/hunyuan-zhang/" + action;
}