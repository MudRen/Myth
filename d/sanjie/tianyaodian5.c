// sanjie tianyaodian5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "east": __DIR__"tianyaolang3",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/juseng": 1 ]) );

  setup();
}
