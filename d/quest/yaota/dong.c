// Room: /d/quest/yaota/dong
//created by kuku@sjshhlj 2002/12

inherit MAGIC_ROOM;
#include <room.h>
#include <ansi.h>
 
void create ()
{
  set ("short", HIC"���ж���");
  set ("long", @LONG

һ�ߵ�������ǰ�ͻ�Ȼ���ʣ������������ǰ������
��Ȼ�޴棬���������ŵ�һ�ɵ��������㣬ֻ�д���
��������ĥ�ѵ��и�֮�˲����������

LONG);

  set("objects", ([ 
]));
  set("exits", ([ 
  "east" : __DIR__"tower9",
]));

  create_door("east", "ʯ��", "west", DOOR_CLOSED);
  setup();
}
