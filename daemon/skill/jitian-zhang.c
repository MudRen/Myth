//Jitian-zhang���������ơ�
//BY Cigar 2002.04.19
#include <ansi.h>; 
inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N����������ȫ�����һ���죡"+HIR""+BLINK"����������Ӧ��"NOR"$N˫�ּ�������$n��$l",
                "dodge":                5,
                "parry":                5,
            "force":            120,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N˫�������߳���������ڽڰθߣ�"+HIY""+BLINK"����������Ȼ��"NOR"$N��ת���Σ�����$n$l",
                "dodge":                5,
                "parry":                5,
            "force":            60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N������$n��ǰһ�������ִ��磬"+HIC""+BLINK"�����������ġ�"NOR"���¶�����$n��$l����һ��",
                "dodge":                5,
                "parry":                5,
            "force":            80,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N�����أ�˫��һ�ᣬʹ�˸�"+HIG""+BLINK"����������"NOR"�Ʋ��ɵ�������$n",
                "dodge":                5,
                "parry":                5,
            "force":            120,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"ֻ��$N���˼�����ͻȻһ���������ض��ɣ�"+HIW""+BLINK"���������ơ�"NOR"˫���쳣������$n$l",
                "dodge":                15,
                "parry":                15,
            "force":            180,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N���һ����˫�����͹��ǰ��һ����"+HIM""+BLINK"���������ҡ�"NOR"�ƺ�Ҫ��$n˺�÷�����Ƕ����",
                "dodge":                5,
                "parry":                5,
            "force":            180,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��ǰһ�����ݣ�������$n���������"+HIG""+BLINK"���������ء�"NOR"һ����Ц��������$n��$l��ݺݵ�һ��",
                "dodge":                5,
                "parry":                5,
            "force":            100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$Nһ������������������۾��Ƶģ�"+HIW""+BLINK"��������ʹ��"NOR"һ����һ�����಻��������$n��$l",
                "dodge":                5,
                "parry":                5,
            "force":            160,
                "damage_type":  "ץ��"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("���������Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 50)
                return notify_fail(CYN"��ľ����޷������ˣ�����������Ϣһ�������ɡ�\n"NOR);
        if( (int)me->query("kee") < 50 )
                return notify_fail(CYN"������������������������Ϣһ�������ɡ�\n"NOR);
        if( (int)me->query("force") < 50 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("kee", 40);
        me->add("force", -20);

        return 1;
}
     string perform_action_file(string func) 
     { 
             return CLASS_D("lunhui") + "/jitian-zhang/" + func; 
     } 
