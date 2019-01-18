// zhaoyangbu.c ����������

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"$n����һ�ݣ�ʹ��"YEL"����ɽ�ơ�"NOR"���ܿ�����һ�С�\n",
	"$N��һ����$nʹ��"HIR"���ƻ��ơ�"NOR"һ�����$Nͷ��Խ����\n",
	"$nһ�����ã�һ��"HIC"���ƺ��ơ�"NOR"�������������Ӱ�Ӷ�û�ˡ�\n",
	"$n����һ�㣬һ��"HIG"�������ơ�"NOR"�ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ��"HIY"���ƽ��ơ�"NOR"����������Ʈ�˿�ȥ��\n",
	"ֻ��$n����һ�ɼ��磬�������ڷ�������ǡ����������е�"HIW"�������ơ�"NOR"��\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
	return notify_fail("�������������û�а취����������\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 100
        ||(int)me->query("force") < 30 )
		return notify_fail("�������������������������������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

int stage(int level)
{
	if( level <20 ) return 1;
	else if ( level < 60 ) return 2;
	else if ( level < 80 ) return 3;
	else if ( level < 140 ) return 4;
	else if ( level < 180 ) return 5;
	else return 6;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return YEL "��ɽ�ơ�" NOR;
	else if ( stage(level) < 2 )
		return HIR "�ƻ��ơ�" NOR;
	else if ( stage(level) < 3 )
		return HIC "�ƺ��ơ�" NOR;
	else if ( stage(level) < 4 )
		return HIG "�����ơ�" NOR;
	else if ( stage(level) < 5 )
		return HIY "�ƽ��ơ�" NOR;
	else 
		return HIW "�����ơ�" NOR;
}
