// sanjie tianmolang4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
��ħ�����ȣ���������Ҫ��������һЩ��֪����ʲô�Ķ���
�������
LONG);

  set("exits", ([
  "east" : __DIR__"tianmolang5",
  "west" : __DIR__"tianmolang3",
]));
  set("outdoors", 0);

  setup();
}
