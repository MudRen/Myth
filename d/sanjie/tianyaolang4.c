// sanjie tianyaolang4.c

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
  "north" : __DIR__"tianyaodian9",
  "west" : __DIR__"tianyaodian7",
  "east" : __DIR__"tianyaodian8",
  "south" : __DIR__"tianyaolang3",
]));
  set("outdoors", 0);

  setup();
}
