//�躣�ķ�
//linghai-force.c
//by dewbaby@sksj 12.2002


#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force",1) < 40)
            return notify_fail(WHT"��Ļ����ڹ���δѧ�ã��޷������躣�ķ���\n"NOR);

    return 1;
}

int practice_skill(object me)
{
        return notify_fail(WHT"�躣�ķ�ֻ�ô�ʦ������ѧ(learn)�����������ȡ�\n"NOR);
}
int stage(int level)
{
        if( level <60 ) return 1;
        else if ( level < 120 ) return 2;
        else if ( level < 180 ) return 3;
        else if ( level < 240 ) return 4;
        else if ( level < 300 ) return 5;
        else if ( level < 360 ) return 6;
        else if ( level < 420 ) return 7;
        else if ( level < 500 ) return 8;
        else return 9;
}

string level_description(int level)
{
        if ( stage(level) < 2 )
                return BLU "ǳ���˺�" NOR;
        else if ( stage(level) < 3 )
                return YEL "�����׺�" NOR;
        else if ( stage(level) < 4 )
                return HIG "����ݺ�" NOR;
        else if ( stage(level) < 5 )
                return HIY "�����ĺ�" NOR;
        else if ( stage(level) < 6 )
                return HIC "��������" NOR;
        else if ( stage(level) < 7 )
                return HIM "���߸���" NOR;
        else if ( stage(level) < 8 )
                return MAG "��������" NOR;
        else if ( stage(level) < 9 )
                return HIR "��Խ����" NOR;
        else
                return HIW "�վ��޺�" NOR;
}

string exert_function_file(string func)
{
       return CLASS_D("linghai") + "/linghai-force/" + func;
}

