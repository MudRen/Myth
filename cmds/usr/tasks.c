// File��/cmds/usr/task.c
// modified by mudring@sjsh......


#include <ansi.h>
int main(object me, string str)
{
        string output;
/*
        int   cur_time;
        cur_time = time();
        if( (cur_time-me->query("last_taskup")) < 40 )             
                return notify_fail("��ٵ�ſ����ٲ鿴taskָ�\n");
        me->set("last_taskup", cur_time);
*/
        if( (int)me->query("sen") < 200 )
            return notify_fail("������ô�㣬Ҳ����task��\n");
        me->add("sen",-20); 
        me->start_busy(2);


        output =HIR"          ��"HIY"   ������ʹ����   "HIR"��\n" NOR;
        output += "������������������������������������������������������\n";
        output += TASK_D->dyn_quest_list();
        output += "������������������������������������������������������\n\n";
        output += YEL"  ��"HIW"��ʾδ���ʹ��     "HIR"��"WHT"��ʾ�Ѿ���ɵ�ʹ��\n"NOR;

        me->start_more(output);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: task

���ָ����������֪Ŀǰ������ʹ��.

HELP
        );
        return 1;
}

