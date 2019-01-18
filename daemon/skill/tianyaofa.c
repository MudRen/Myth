// tianyaofa.c ���������񷨡�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":		"$N����һ�����У�����$w��һ��"RED"������ʽ��"NOR"������������$n��$lײȥ",
                "dodge":                10,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һת��һ��"YEL"������ơ�"NOR"ʹ����������$w������$n��$l��$nֻ������������",
                "dodge":                15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":		"$N�趯$w��һʽ"MAG"�����������"NOR"����ʱ�������죬��ͷ��������$n��$l��ȥ",
                "dodge":                15,
		"parry":		0,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":		"$N����$wȴ����һ����һ��"WHT"������ʴ�ա�"NOR"�����ޱȵش���$n$l����ʱ���ذ�",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "action":		"$N�趯$w��ʹ��"CYN"��ǧ�����ǡ�"NOR"����ǧ����ó�������$w��$n��ȥ",
                "dodge":                0,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":		"$N�����﷢���������У��߾�$w��$n������ħ��ʴ�򣬺�������"HIB"����������"NOR,
                "dodge":                -20,
		"parry":		-20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":		"$N����һ�����У�����$w��һ��"HIR"����������"NOR"�����������$n��$l����ɨȥ",
                "dodge":                -20,
		"parry":		-20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���һ����һ��"HIC"��������ء�"NOR"ʹ����$nֻ�������µߵ��������ת",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취���������񷨡�\n");

        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ������������񷨡�\n");

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
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�������񷨡�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ���������񷨡�\n");
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

string perform_action_file(string action)
{
return CLASS_D("sanjie") + "/tianyaofa/"+action;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 80 ) return 4;
	else if ( level < 120 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 200 ) return 7;
	else if ( level < 240 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return RED "����ʽ��" NOR;
	else if ( stage(level) < 2 )
		return YEL "����ơ�" NOR;
	else if ( stage(level) < 3 )
		return MAG "�������" NOR;
	else if ( stage(level) < 4 )
		return WHT "����ʴ��" NOR;
	else if ( stage(level) < 5 )
		return CYN "ǧ������" NOR;
	else if ( stage(level) < 6 )
		return HIB "��������" NOR;
	else if ( stage(level) < 7 )
		return HIR "��������" NOR;
	else if ( stage(level) < 8 )
		return HIC "�������" NOR;
	else 
		return HIW "��������" NOR;
}
