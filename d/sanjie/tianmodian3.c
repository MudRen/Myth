// sanjie tianyaodian3.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�׸�ǰ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "north": __DIR__"tianmodian4",
  "south": __DIR__"tianmolang2",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/goujiang": 1,
                __DIR__"npc/huojiang": 1,
                __DIR__"npc/tiejiang": 1 ]) );

  setup();
}
