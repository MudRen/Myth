// sanjie tianyaodian.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "south": __DIR__"tianyaodian0",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/datianyao": 1 ]) );

  setup();
}
