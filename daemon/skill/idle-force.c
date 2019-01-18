inherit SKILL;
string perform_action_file(string func)
{
        return __DIR__"idle-force/" + func;
}

#include <ansi.h>

string level_description(int level)
{
	if ( level < 10 )
		return BLU "������ʼ" NOR;
	else if ( level < 20 )
		return HIB "�����;" NOR;
	else if ( level < 30 )
		return YEL "�ռ�����" NOR;
	else if ( level < 40 )
		return CYN "��ͷ����" NOR;
	else if ( level< 50 )
		return HIW "����ľ��" NOR;
	else 
		return HIR "�޿ɾ�ҩ" NOR;
}

