//������
//fenxin-spells.c
//by dewbaby@sksj 12.2002


#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells") <= (int)me->query_skill("fenxin-spells") )
             return notify_fail(WHT"��Ļ���������Ϊ���������޷������������\n"NOR);
        if( (int)me->query("str") < 20 )
             write(WHT"�㻹��Ҫ��ǿ��������!������Ǹ����ı�Ǯ!\n"NOR,me);
        if( (int)me->query("bellicosity") > 270 )
             return notify_fail(HIR"���ɱ��̫�ߣ��޷�ѧ��������\n"NOR);
    return 1;
}
int practice_skill(object me)
{
        return notify_fail(WHT"������ֻ����ʦ��ѧ(learn)�����������ȡ�\n"NOR);
}

int stage(int level)
{
             if ( level <  80 ) return 1;
        else if ( level < 150 ) return 2;
        else if ( level < 230 ) return 3;
        else if ( level < 310 ) return 4;
        else if ( level < 390 ) return 5;
        else if ( level < 470 ) return 6;
        else if ( level < 550 ) return 7;
        else if ( level < 630 ) return 8;
        else return 9;
}

string level_description(int level)
{
        if ( stage(level) < 1 )
                return BLU "����" NOR;
        else if ( stage(level) < 2 )
                return YEL "����" NOR;
        else if ( stage(level) < 3 )
                return HIG "����" NOR;
        else if ( stage(level) < 4 )
                return CYN "����" NOR;
        else if ( stage(level) < 5 )
                return HIM "����" NOR;
        else if ( stage(level) < 6 )
                return MAG "����" NOR;
        else if ( stage(level) < 7 )
                return HIR "����" NOR;
        else
                return HIW "����" NOR;
}

string cast_spell_file(string spell)
{
        return CLASS_D("linghai") + "/fenxin-spells/" + spell;
}

string type() 
{
        return "magic";
}


