// sanjie tianyaodian2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�׸�ǰ��");
  set ("long", @LONG
	
һ����������Ĺ��
LONG);

  set("exits", ([
  "north": __DIR__"tianmodian1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/leijiang": 1 ]) );

  setup();
}
