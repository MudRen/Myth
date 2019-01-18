// houquan.c ��ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "\n$����΢����������ǰ�˳���һʽ���ɺ�ժ�ҡ�����צֱ����ץ��$n��˫��",
        "force" : 130,
        "dodge" : 5,
        "parry": 10,
        "damage_type" : "ץ��",
        ]),
([      "action" : "$N������Σ�һʽ�������֦��������ֱ��������$n�ļ羮��Ѩ",
        "force" : 150,
        "dodge" : 10,
        "parry": 20,
        "damage_type" : "����",
]),
([      "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ��Գ�����桹������$n������",
        "force" : 180,
        "dodge" : 10,
        "parry": 25,
        "damage_type" : "����",
]),
([      "action" : "\n$N��Ȼ����һ�ţ�ʹһʽ���˷���Ӱ����˫�������޶���һצץ��$n���ؿ�",
        "force" : 180,
        "dodge" : 25,
        "parry": 20,
        "damage_type" : "����",
]),
([      "action" : "$N����һ������һ������ʹһʽ��ˮ�����¡���˫צ������$n��С��",
        "force" : 170,
        "dodge" : 15,
        "parry": 10,
        "damage_type" : "����",
]),
([      "action" : "$N�͵����ϸ߸�Ծ��һʽ�����ժ�ǡ����Ӹ����£�һצ����$n��ͷ��",
        "force" : 190,
        "dodge" : 20,
        "parry": 20,
        "damage_type" : "ץ��",
]),
([      "action" : "$N����һ�Σ���ƮƮ��ץ��$n��$1",
        "force" : 80,
        "dodge" : -20,
        "parry": -20,
        "damage_type" : "ץ��",
]),
([      "action" : "$N��ȭ�����Ŷ���$n$1ֱ����ȥ",
        "force" : 190,
        "dodge" : 20,
        "parry": 20,
        "damage_type" : "����",
]),
([      "action" : "$N֨��һ���ֽУ��������ϣ�����$nץ��",
        "force" : 200,
        "dodge" : 0,
        "parry": 0,
        "damage_type" : "ץ��",
]),
});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ȭ������֡�\n");
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ��ȭ��\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷�����ȭ��\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("TP_perform");
        if( !me->query_temp("TP_perform") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 10)
                return notify_fail("���������������ȭ��\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/houquan/" + func;
}
