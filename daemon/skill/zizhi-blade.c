// ��������
//��ԯ��Ĺ���⹥������
//by ivy 2002.2.9
//������ɽѩ

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$Nһ��"+HIW"��������ɽѩ��"NOR"������$w����һ�ɿ�磬����$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$wһ�Σ�������������$n��$l��һ��"+HIM"���޻�ֻ�к���"NOR"ʹ��ǡ���ô�",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�����㱣�����$wƮҡ������һ��"HIG"��������������"NOR"бб�Ŀ���$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����ִ��$w�����ַ��ŵ��������Ƴ���һ��"HIC"����ɫδ������"NOR"ɨ��$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��Цһ����һ��"HIR"����ս���ġ�"NOR"������$w����˿˿����������ϻ���$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���һ����ʹ��һ��"HIM"�����߱��񰰡�"NOR"��˫�ֽ���$w
���ű��˵�ɱ��������$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���һ����ʹ��һ��"HIB"��Ը�����½���"NOR"��˫�ֽ���$w
���ű��˵�ɱ��������$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),        ([      "action":
"$N���һ����ʹ��һ��"RED"��ֱΪն¥����"NOR"��˫�ֽ���$w
���ű��˵�ɱ��������$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 80 )
                return
notify_fail("�������������û�а취ѧ���ɵ�����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return
notify_fail("���������һ�ѵ�����ѧ���ɵ�����\n");

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
                return
notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/zizhi-blade/" + func;
}

