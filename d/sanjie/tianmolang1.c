// sanjie tianmolang1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
�׸������ȣ���������Ҫ��������һЩ��֪����ʲô�Ķ���
�������
LONG);

  set("exits", ([
  "northwest" : __DIR__"tianmolu6",
  "south" : __DIR__"tianmodian1",
]));
  set("outdoors", 0);

  setup();
}
