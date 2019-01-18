// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/daemon/class/force/" + func;
}

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "��������" NOR,
		HIB "�����ž�" NOR,
		HIY "����Ѿ�" NOR,
		HIB "��Ϣ�Ƴ�" NOR,
		YEL "��������" NOR,
		YEL "Ӣ������" NOR,
		YEL "ͨ���ڼ�" NOR,
		CYN "��Ȼ��ͨ" NOR,
		HIC "������˫" NOR,
		HIC "������" NOR,
		HIW "��ɲ�" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
