inherit ROOM;
#include <ansi.h>
void create ()
{
          set ("short", HIC"ѩ�ݴ���"NOR);
  set ("long", HIM@LONG

    ���ſ�վ��һ������,����ס��һ�������Ĺ���.

  �����޹��Ķ�����һ����԰��ʢ����˵�������ֵ��ʻ���

  ������Խ��Խ�
LONG);
  set("exits", 
  ([ //sizeof() == 8 
     "west" : "/u/ffff/home4",
         "enter" :"/u/ffff/xueroom",
]));
   set("objects",
 ([ //sizeof() == 1
    "u/ffff/npc2/guard1" : 1,
     "u/ffff/gold" : 1,
]));
     set("no_clean_up", 0);
     setup();
}
int valid_leave(object me, string dir)
{
   if (dir == "enter" ) {
if (objectp(present("guard", environment(me)))) 
        return notify_fail("ѩ��Ů��������ס��˵����˽���صأ����˲�Ҫ���ˣ����ǲ�Ҫ��ȥΪ�á�\n");
        }   
        return ::valid_leave(me, dir);
}
