// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "��ͨ����" NOR,
		BLU "��֪һ��" NOR,
		HIB "֪�����" NOR,
		HIB "�Ĳ��Ȼ" NOR,
		YEL "��ѧ���" NOR,
		YEL "�߲�˶��" NOR,
		CYN "��ѧ����" NOR,
		HIW "ѧ��Ž�" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

