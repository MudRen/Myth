//�������ơ� suiyu-zhang.c by cigar 2002.01
//menpai skill

inherit SKILL;

#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N����΢�֣�����һ��ʹ��һ��"+BLINK""+HIW"������"NOR"��һֻѩ�׵�˫��̽��$n��$l",
                "dodge":                15,
                "parry":                15,
                "force":                140,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$Nٿ��һ��ת��˫��������һĨ���ֳ�"BLINK""+HIC"�����ġ�"NOR"֮״���ſ�һ����һ������ֱ��$n",
                "dodge":                -35,
                "parry":                -35,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����΢б���漴���һ�������ֺ��ƺ�צʹ��"BLINK""+HIM"�����ġ�"NOR"������$n��$l",
                "dodge":                5,
                "parry":                5,
                "force":                80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"BLINK""+HIB"�����ҡ�"NOR"��˫�ֻ����쳣��׼$n��$l��ȥ",
                "dodge":                -5,
                "parry":                -10,
                "force":                80,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N������Σ�����ƮƮ�����ĳʱ��̣�һ��"BLINK""+HIG"�����ҡ�"NOR"����$n$l",
                "dodge":                15,
                "parry":                15,
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"BLINK""+HIY"�������"NOR"�����Ծ���䲻�������ǰ��׼$n$l�߳�һ��",
                "dodge":                -5,
                "parry":                -5,
                "force":                110,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$n$l���������һ��"BLINK""+HIR"����ϡ�"NOR"��צ����ͬһ��λץ��",
            "dodge":                15,
                "parry":                15,
                "force":                160,
                "damage_type":  "ץ��"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("�������Ʊ�����֡�\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������̫�����޷��������ơ�\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query("YOUNING");
        if( !me->query("YOUNING") ) {
        return action[random(sizeof(action))];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 40)
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("kee") < 40 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("kee", 40);
        me->receive_damage("sen", 40);
        me->add("force", -10);

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 4 );
                switch(random(3)) {
                        case 0: return "��������������һ�����죬�����ǹ����������\n";
                        case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
                        case 2: return "ֻ����$n��$l��������һ�� ...\n";
                }
        }
}

string perform_action_file(string func)
{
return CLASS_D("youning") + "/suiyu-zhang/" + func;
}
