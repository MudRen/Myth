// sanjie tianyilang3.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
���ȴ����������رߣ�������ڳ����������д���������
������Ȼ���˼��ɾ���
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilang5",
  "west" : __DIR__"tianyilang2",
  "south" : __DIR__"tianyidian3",
]));
  set("outdoors", 1);

  setup();
}
