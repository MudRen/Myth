// sanjie tianyaodian6.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "west": __DIR__"tianyaolang3",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/linggui": 1 ]) );

  setup();
}
