inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "����");
  set ("long", @LONG

������д��һ�����ӣ���������ɽ�����ǣ��ľ��ɶ�
�����桱��
LONG);
 
  set("exits", ([
        "north"  : __DIR__"tianjing",
        "south"  : __DIR__"sanmen",
      ]));
  create_door("south", "ʯ��", "north", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}

