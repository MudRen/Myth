// perception.c
#include <ansi.h>

inherit SKILL;

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "��ͷ����" NOR,     
		HIB "��������" NOR,
		HIB "���ֿ��" NOR,     
		CYN "�������" NOR,
		HIC "�ֵ�����" NOR,     
		HIW "������͵" NOR,
	});

	grade = level / 10;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

