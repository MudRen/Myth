// huxiaojian.c ����Х�ʽ���

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ�����е�$w��ʹ��һ��"HIR"��һХ�쳾����"NOR"��˲��̳���ʮ������$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-10,
                "parry":                -20,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"action":		"$Nһ������$n��ʹ��һ��"HIC"����Х��������"NOR"��$n��æ���Ա�һ����\n����$Nһ�˾��������е�$wͻȻ���˹�����ת������$n��$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		50,
		"damage_type":		"����"
	]),
	([	"action":		"$N����$w�������������⻷��һ����������$n��ǰ̤��һ����$N���ֽ�ָ�Ѵ���$n��$l������һ��"HIB"����Х����١�"NOR,
		"dodge":		-20,
                "parry":                -20,
		"damage":		55,
		"damage_type":		"����"
	]),
	([	"action":		"������"HIW"����Х����"HIW"��$Nһת������$n������$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		60,
		"damage_type":		"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����Х�ʽ���\n");
	if( !(ob = me->query_temp("weapon")) ||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return CLASS_D("sanjie")+"/huxiaojian/"+action;
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

        if( (int)me->query("kee") < 100 || (int)me->query("force") < 40 )
		return notify_fail("�����������������û�а취��ϰ��Х�ʽ���\n");
        me->receive_damage("kee", 30);
        me->add("force", -6);
//        write("�㰴����ѧ����һ�黢Х�ʽ���\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
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
