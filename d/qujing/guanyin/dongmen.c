inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������һ�����ţ���������һ��ʯ�壬����д�š��ڷ�ɽ
�ڷ綴���������֡���ǰ������ɢ�����Ƚ��յ�ʯ�š�
LONG);
  set("outdoors", __DIR__);
 
 set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/guai1" : 2,
        ]));

  set("exits", ([
       "south" : __DIR__"tianjing",
        "north"  : __DIR__"lingdao5",
      ]));
create_door("south", "ʯ��", "north", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}

int valid_leave(object me, string dir)
{       
   if (! me->query_temp("apply/name") ||
   me->query_temp("apply/name")[0] != "������")
   {
   if (dir == "south") 
   return notify_fail("С��̽��ͷ�ȵ����ҿ����ǻ����ˣ�\n");
   return ::valid_leave(me, dir);
      }
  return 1;
 }
