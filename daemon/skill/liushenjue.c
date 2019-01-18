// liushenjue.c ���������

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ��"HIC"�����񼲡�"NOR"�����ֿ������ס�����ɵ��������$n��$l",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action": 		"$N˫��һ������"YEL"���޺�ж��"NOR"��˫��ǿ��������������ǧ���ж$N����",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([	"action":		"ֻ��$Nһת���ۻ�Ե���������׶����$n��$l�����ѽ⼡���⣬ȴ����һ��"HIY"����ս⡹"NOR"",
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action":		"$N˫��һ����һ��"HIM"�������ҡ�"NOR"Ѹ�ٷ��ҵ�������ʽ˲����ǧ�ٻ�����$n����ʤ��",
		"dodge":		20,
		"parry":		20,
		"force":		140,
		"damage_type":	"����",
                        "weapon":		"����", 
	]),
            ([	"action":		"$Nһ��"RED"��������"NOR"�������������ȵĻ�������������$n��$l",
		"dodge":		30,
		"parry":		10,
		"force":		70,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
            ([	"action":		"����$Nһ��ŭ�������������ɾ���������һʽ"HIG"�������ơ�"NOR"������$n��$l",
		"dodge":		10,
		"parry":		-10,
		"force":		220,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	    ([  "action": 		HIR"$N˫�ƺ�ʮ����Ŀ���񣬴߹�������һ��֮���ں��ˡ������������������һ�ι�����$n"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                500,
                "damage_type":  "����",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("liushenjue_per");
        if( !me->query_temp("liushenjue_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�������\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ���������\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("sanjie") + "/liushenjue/" + func;
}

int stage(int level)
{
	if( level <20 ) return 1;
	else if ( level < 60 ) return 2;
	else if ( level < 100 ) return 3;
	else if ( level < 140 ) return 4;
	else if ( level < 180 ) return 5;
	else if ( level < 220 ) return 6;
	else return 7;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIC "���񼲡�" NOR;
	else if ( stage(level) < 2 )
		return YEL "�޺�ж��" NOR;
	else if ( stage(level) < 3 )
		return HIY "��ս⡡" NOR;
	else if ( stage(level) < 4 )
		return HIM "�����ҡ�" NOR;
	else if ( stage(level) < 5 )
		return RED "������" NOR;
	else if ( stage(level) < 6 )
		return HIG "�����ơ�" NOR;
	else 
		return HIW "�����һ" NOR;
}
