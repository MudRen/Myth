// sanjie tianyaodian4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�׸����");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "south": __DIR__"tianmodian3",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/dianjiang": 1 ]) );

  setup();
}
