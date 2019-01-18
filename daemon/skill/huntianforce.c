// huntianforce.c  �����챦����

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("���챦��ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("sanjie") + "/huntianforce/" + func;
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
	else if ( level < 280 ) return 9;
	else return 10;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return WHT "�����̡�" NOR;
	else if ( stage(level) < 2 )
		return HIM "õϼ����" NOR;
	else if ( stage(level) < 3 )
		return YEL "�����ء�" NOR;
	else if ( stage(level) < 4 )
		return HIC "��ѩ����" NOR;
	else if ( stage(level) < 5 )
		return MAG "���Ǻӡ�" NOR;
	else if ( stage(level) < 6 )
		return CYN "�����硡" NOR;
	else if ( stage(level) < 7 )
		return HIB "��׺���" NOR;
	else if ( stage(level) < 8 )
		return HIY "���ء�" NOR;
	else if ( stage(level) < 9 )
		return HIR "Ѫ�ԡ�" NOR;
	else 
		return HIW "�����桡" NOR;
}