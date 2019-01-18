//����ɥ����kusang-bang.c

/*
��ɥ��    dodge  0    parry  -10    damage  25
��ɥ��������ף����ƶ���ƫ�棬���˷���ʤ�������˰���
��������Ϊ�������־������顣
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "��糤��",
                "action":
"$N����һ�����У�����$w��һ�С���糤�š������������$n��$l����ɨȥ",
                "dodge":                15,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "Թ������",
                "action":               
"$N����һת�������ɫ��һ�С�Թ�����项ʹ����\n����$w����մ����$n��˦Ҳ˦����",
                "dodge":                -15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ҹ����",
                "action":
"$N�趯$w������һЦ��һ�С���ҹ���项���ŵ���׹�����$n��$l",
                "dodge":                10,
		"parry":		0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��Ұ��ʳ",
                "action":
"$N��¶����֮ɫ������$wȴ����һ����һ�С���Ұ��ʳ�������ޱȵش���$n$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���¶���",
                "action":
"$N��������һ��������$wͻȻ�������ߣ���������֮�⣬\nһ�С����¶��С�����ɭɭ��������$n$l",
                "dodge":                -5,
		"parry":		0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l���������ġ�С¥ҹ�ޡ�",
                "dodge":                5,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����ɥ����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�������ɥ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        return action[random(sizeof(action))];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ��ɥ����\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���ɥ����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("kusang-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

