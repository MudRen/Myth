//in wangxian DIR
//cave1

#include <ansi.h>
inherit ROOM;
void create()
{
          set("short","��¥��");
          set("long",@LONG
����ͤ���棬������һƬ�ķϵ���¥����¥�����ڱ̲�
֮�ϡ����е�һ����¥����һ�ڸɿݵ��Ͼ����ྮ�ߵ�
ʯǽ����һ����(dong)�����������ģ���֪����ʲ
ô�������
LONG); 
         
           set("exits",([ /* sizeof() == 1 */
           "west" : __DIR__"yuexia",
           ]));
           set("item_desc",([
             "dong":"�ⶴ��������һƬ��ʲô����������\n",
           ]));        
          
           setup();
}

void init()
{
          add_action("do_enter","zuan");
          add_action("do_enter","enter");
}
          
int do_enter(string arg)
{
       object me = this_player();
       if(! arg || arg !="dong") return 0;
       if (me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ģ�\n");
       if (arg == "dong") {
               message("vision", me->name() + "һ����������˺ڶ���\n", environment(me), ({me}));
               write("�㼱�Ҵҵ��������꣬ȴ�����˶�����ʯ�飬���۵�ֱ������ᡣ\n");
                me->move(__DIR__"cave2");
               message("vision", me->name() + "���˽�����ͷ��ײ����ɽʯ�ϡ�\n", environment(me), ({me}));
               return 1;
       }
       return notify_fail("���������갡��\n");       
}


