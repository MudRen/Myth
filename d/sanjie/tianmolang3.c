// sanjie tianmolang3.c

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
  "east" : __DIR__"tianmolang4",
  "southwest" : __DIR__"tianmolu9",
]));
  set("outdoors", 0);

  setup();
}
