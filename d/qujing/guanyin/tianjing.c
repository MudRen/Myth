inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "�쾮");
  set ("long", @LONG

ֻ��������򽻴䣬�������У��ԴԻ������ش����㡣
ȴҲ�Ǹ�����֮����С�����Ĵ��߶���
LONG);
 
  set("exits", ([
 "north" : __DIR__"dongmen",
        "south"  : __DIR__"ermen",
      ]));
create_door("north", "ʯ��", "south", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}

