// sanjie tianyaolang1.c

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
  "north" : __DIR__"tianyaolang2",
  "west" : __DIR__"tianyaodian1",
  "east" : __DIR__"tianyaodian2",
  "south" : __DIR__"tianyaomen",
]));
  set("outdoors", 0);

  setup();
}
