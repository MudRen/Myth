// sanjie tianyaodian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "east": __DIR__"tianyaolang1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/yanjiumei": 1 ]) );

  setup();
}
