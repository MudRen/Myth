//Cracked by Roath

#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "action":       "$Nʹһ�С���Ӣ�ͷס�����������Ʈ������$w����ʵʵ�ó���㽣���׷���������$n$l",
        "damage":        20,
        "damage_type":  "����"
        ]),
    ([  "action":       "$N�趯$w��һʽ�������һ�����������$n����һ�Σ�����$w�������佣��Ю�Ż�����������$n��$l",
        "damage":        25,
        "damage_type":  "����"
    ]),
    ([ "action":        "$N������$nһת������$w����һָ��һʽ���������꡹�ó����콣Ӱ����$n$l�����ӳ�����",
        "damage":        20,
                "damage_type":  "����"
        ]),
    ([  "action":       "$N����ƮȻ�����ڰ��������һ������Ȼһʽ�����Ƿɻ�������$w�������޵�������$n��$l",
        "damage":       20,
                "damage_type":  "����"
        ]),
    ([  "action":       "$N�������࣬һʽ��ϸ���ɷ��ء�ͷ�½��ϣ�һ�С������䡹����$w���һ����������$n��$l",
        "damage":       40,
        "damage_type":  "����"
    ]),
    ([  "action":       "$Nһ�����ʹ�������컨�꡹������$w�ó����컨�꣬Ѹ����������$n��$l",
        "damage":       30,
        "damage_type":  "����"
    ]),
    ([  "action":    "$N��̾һ��������$w����һ����һʱ���仨���⡹��$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l",
        "damage":       40,
        "damage_type":  "����"
    ]),

});

int valid_learn(object me)
{
        object ob;

    if( (int)me->query_skill("zixia-shengong",1) < 50)
        return notify_fail("�����ϼ�񹦻�򻹲�����\n");

if( (int)me->query_skill("yujianshu",1) < 50)
return notify_fail("�����������򻹲�����\n");

    if( (int)me->query("max_force") < 300 )
        return notify_fail("��������������������Ľ���\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ѧϰ������\n");

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
        object ob;

    if( (int)me->query("kee") < 30
    ||  (int)me->query("force") < 5 )
        return notify_fail("�����������������û�а취��ϰ�Ľ���\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ϰ��������\n");

    me->receive_damage("kee", 30);
        me->add("force", -5);
//    write("�㰴����ѧ����һ���Ľ���\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") + "/mindsword/" + action;
}
