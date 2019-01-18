//TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               "$Nʹһ�С�һҶ��Ƽ��󺣡�������$wһ�ڣ����μ�����ɣ����˺�һ������$n��$l��",
                "damage_type":  "����"
        ]),
        ([      "action":               "$N$w�����������⣬һ�С������δ�����꡹����������$n��$l��",
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w����������ˮ��һ�С�˥��б�������֡���бб����$n��$l",
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w���⼤����һ�С�����Ӱ�հ����̡���ն��$n��",
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w���裬�������Ŵشأ�һ�С����ܻ���֪��ɫ����ƮƮ������$n��ȥ",
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w����ɭȻ��һ�С���Ƽ��Զ��������ֱ��$n$l",
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹһ�С��ͷ������仨�졹������$w�ڶ����������ն��$n��$l",
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;
       if( (string)me->query("gender") != "����" )
                return notify_fail("����������ֻ�����Բ��������书��\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ���������������\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
        return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$nʹ��һ�С���ҡɽ�������������е�$vɢ��˿˿��������$N��$w��\n",
        "$n����$v���������һ�С����������б��������Ӱ��ͻȻ����һ�ƹ�â�Ӳ��滮��$N֮�ؾȡ�\n",
        "$n����΢�٣����е�$v����һ�����⣬һ�С����������һ�С�������$N��$w��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С�˪���Ҷ����������е�$v����������$N�Ĺ����沨��ɢ��\n",
"$n���μ��ˣ�����$v���·��裬һ�С������������󡹣���ס$N����ʽ��\n",
"$n���е�$v�����䵶����һ�С�������Ӱ���������������ࡣ\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}

string perform_action_file(string action)
{
return CLASS_D("youning") + "/qiushen-blade/" + action;
}


