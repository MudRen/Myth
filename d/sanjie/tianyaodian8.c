// sanjie tianyaodian8.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "west": __DIR__"tianyaolang4",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/fengmei": 1 ]) );

  setup();
}
