// sanjie tianyilang5.c

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
  "north" : __DIR__"tianyirest",
  "west" : __DIR__"tianyidian4",
  "south" : __DIR__"tianyilang3",
]));
  set("outdoors", 1);

  setup();
}
