//in wangxian DIR
// cave2
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",WHT"�ڶ���");
          set("long",@LONG
�������䳱ʪ��ʯ����̦޺������ż��������ˮ�δ�����ɽʯ�ϵ�
���������������խ����������ȱ�٣����㼸����Ϣ��
LONG
);
          setup();
          
}

void init()
{
          add_action("do_climb",({"climb", "pa", "zuan"}));
}

int do_climb(string arg)
{
       object me = this_player();
       if(!arg || arg !="down") 
               return notify_fail("�㳯��������\n");
       if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");
       if ( arg=="down"){
       if (random(me->query_str()) >= 20){
               message("vision", me->name() + "�˾�˫�磬�ֽż��ã���ǰ��ȥ��������ȷʵ̫С������ǰ�С�\n", environment(me), ({me}));
               tell_object(me,"���˾�˫�磬�ֽż��ã���ǰ��ȥ��������ȷʵ̫С������ǰ�С�\n"NOR);
               me->start_busy(8);
               remove_call_out("out1");
               call_out("out1", 10, me);
               return 1;
       }
       else {
               message("vision", me->name() + "��������������ϥ����ǰ����\n", environment(me), ({me}));
               tell_object(me,"�㹭������������ϥ����ǰ����\n");
       }
       tell_object(me,HIM"\n������һ�����������...\n\nͻȻ������ǰ��Ȼһ�����ƺ��ҵ��˳��ڣ�\n"NOR);
       me->move(__DIR__"cave3");
       me->start_busy(1);
       message("vision", me->name() + "�Ӷ������˳�����\n", environment(me), ({me}));
       return 1;
       }
       return notify_fail("�㳯��������\n");
}

void out1(object me)
{
       tell_object(me,"\n��ֻ�����������弸����Ƕ�ڶ��У�ֻ�ܹ�������������ϥ����ǰ����\n"NOR);
       me->start_busy(10);
       remove_call_out("out");
       call_out("out", 10, me);
}

void out(object me)
{
       tell_object(me,HIM"\n������һ�����������...\n\nͻȻ������ǰ��Ȼһ�����ƺ��ҵ��˳��ڣ�\n"NOR);
       me->move(__DIR__"cave3");       
       message("vision", me->name() + "�Ӷ������˳�����\n", environment(me), ({me}));
}

