// sanjie tianyaodian0.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�е�");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "north": __DIR__"tianyaodian",
  "south": __DIR__"tianyaodian9",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/yaoshuai": 1 ]) );

  setup();
}
