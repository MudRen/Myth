// tianmogong.c  ����ħ����

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("tianmogong") )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��ħ����\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("sanjie") + "/tianmogong/"+spell;
}

string type() { return "magic"; } 

int stage(int level)
{
	if( level <80 ) return 1;
	else if ( level < 160 ) return 2;
	else if ( level < 240 ) return 3;
	else if ( level < 280 ) return 4;
	else return 5;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIR "��ħʴ��" NOR;
	else if ( stage(level) < 2 )
		return HIY "��ħʴ��" NOR;
	else if ( stage(level) < 3 )
		return HIC "��ħʴ��" NOR;
	else if ( stage(level) < 4 )
		return HIM "��ħʴ��" NOR;
	else 
		return HIW "��ħ����" NOR;
}