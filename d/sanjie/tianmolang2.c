// sanjie tianmolang2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
�縮�����ȣ���������Ҫ��������һЩ��֪����ʲô�Ķ���
�������
LONG);

  set("exits", ([
  "north" : __DIR__"tianmodian3",
  "southeast" : __DIR__"tianmolu7",
]));
  set("outdoors", 0);

  setup();
}
