// sanjie tianyaodian4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "west": __DIR__"tianyaolang2",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/canhun": 1 ]) );

  setup();
}
