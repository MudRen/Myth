// bawang-qiang.c ������ǹ����

/*
����ǹ��    dodge  10    parry  -10    damage  25
ǹΪ�ٱ�֮��������ǹ�������ͣ����Դ�ǹ����ͻ��
���ֵ����ܷ��ء�ȱ���ǲ������飬����Ҫ�ӻ��Ǻ�
���׵ġ�
*/

inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nʹһ�С�ӭ����������������$w��������$n���ţ���ɤ��ǰ��",
                "damage":               30,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���㾫�񣬶���$w��һ�С�����Ѱ�ߡ�����$n$l",
                "damage":               20,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ���粽��ʹһ�С���ɽ��ˮ��������$w�������ٴ���$n��$l",
                "damage":               25,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "����"
        ]),
         ([      "action":
"$Nһ��ǹ�ѣ�ž����һ���������ǹ�����������ң�����ʵʵ����$nȫ��Ҫ��",
                "damage":               25,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "����"
        ]),
         ([      "action":
"ֻ��$Nһ��б�磬ʹ�����ٻ������ơ�������$w����һ�����������¶��ϼ���$n$l",
                "damage":               35,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����һ��������$w�����벻���ĽǶȴ���$n��$l��\n��һ�С����߳������������磬�����ޱ�",
                "damage":               15,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��������Ͷ���ơ�������б�ɣ��Ӳ���ͻ��һǹ������$n$l",
                "damage":               20,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������ߣ����Ǻ���һ��ת����æ��ʹ��һ�С�����ǹ����$wһͦ����$n$l",
                "damage":               30,
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취������ǹ����\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ�����ǹ����\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("fighter") + "/bawang-qiang/" + func;
}

