// sanjie tianyaolang3.c

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
  "north" : __DIR__"tianyaolang4",
  "west" : __DIR__"tianyaodian5",
  "east" : __DIR__"tianyaodian6",
  "south" : __DIR__"tianyaolang2",
]));
  set("outdoors", 0);

  setup();
}
