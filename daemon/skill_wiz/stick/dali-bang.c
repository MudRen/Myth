//����ɥ����kusang-bang.c

/*
������    dodge  10    parry  -10    damage  30
���Ŵ������������ͣ������м�
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "������ɽ",
                "action":
"$N����һ�����У�����$w��һ�С�������ɽ�������ź���������$n��$l��ȥ",
                "dodge":                10,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":               
"$N����һת��һ�С�������ơ�ʹ������Χ������ʯ�ҷɣ�
������$w������$n��$l����Ҳ�㲻����",
                "dodge":                15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$N�趯$w��һʽ����������������ͷ��������$n��$l��ȥ",
                "dodge":                15,
		"parry":		0,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�˷�����",
                "action":
"$N�趯$w��ʹ�����˷����꡹���ó�������$w��$n��ȥ",
                "dodge":                0,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취����������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ��������\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("dali-bang", 1) > 30 
	 && (int)me->query_skill("dali-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 200);
	}
}

