// huxiaoquan.c ����Х��ȭ��

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ���֣�ʹ��һ��"HIR"��һХ�쳾����"NOR"��˲��̳���ʮ��ָ��$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action": 		"$Nһ�ƻ���$n��ʹ��һ��"HIC"����Х��������"NOR"��$n��æ���Ա�һ����\n����$Nһ�˾�������ͻȻ���˹�����ת������$n��$l",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([	"action":		"$N�����������������⻷��һ����������$n��ǰ̤��һ����$N���ֽ�ָ�Ѵ���$n��$l������һ��"HIB"����Х����١�"NOR,
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([  	"action": 		HIR"������"HIW"����Х����"HIW"��$Nһת������$n���ִ�Ҹ�·��ִ���$n��$l"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                220,
                "damage_type":  "����",
                        "weapon":		"����ʳָ",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("����Х��ȭ������֡�\n");
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
        if( (int)me->query("kee") < 100
        ||      (int)me->query("force") < 30 )
                return notify_fail("�����������������û�а취��ϰ��Х��ȭ��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ�黢Х��ȭ��\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("sanjie") + "/huxiaoquan/" + func;
}

int stage(int level)
{
	if( level <60 ) return 1;
	else if ( level < 120 ) return 2;
	else if ( level < 180 ) return 3;
	else return 4;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIR "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 2 )
		return HIC "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 3 )
		return HIB "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else 
		return HIW "��"+chinese_number( stage(level) )+"�㡡" NOR;
}
