// sanjie tianyaolang2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
���������ȣ���������Ҫ��������һЩ��֪����ʲô�Ķ���
�������
LONG);

  set("exits", ([
  "north" : __DIR__"tianyaolang3",
  "west" : __DIR__"tianyaodian3",
  "east" : __DIR__"tianyaodian4",
  "south" : __DIR__"tianyaolang1",
]));
  set("outdoors", 0);

  setup();
}
