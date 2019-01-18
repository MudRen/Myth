// dodge.c
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"���Ǻ�$p$lƫ�˼��硣\n",
	"���Ǳ�$p����ض㿪�ˡ�\n",
	"����$n����һ�࣬���˿�ȥ��\n",
	"���Ǳ�$p��ʱ�ܿ���\n",
	"����$n����׼�������Ų�æ�ض㿪��\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "���ֱ���" NOR,     
		BLU "������ӯ" NOR,
		HIB "�����鶯" NOR,     
		HIB "��������" NOR,
		HIB "�����ɺ�" NOR,
		CYN "̤ѩ�޺�" NOR,
		CYN "��Ƽ��ˮ" NOR,
		CYN "��ȥ���" NOR,     
		HIC "һкǧ��" NOR,
		HIC "���λ�Ӱ" NOR,
		HIW "��ն���" NOR     
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

