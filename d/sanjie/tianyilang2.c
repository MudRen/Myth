// sanjie tianyilang2.c

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
  "north" : __DIR__"tianyilang4",
  "east" : __DIR__"tianyiting1",
  "south" : __DIR__"tianyidian2",
]));
  set("outdoors", 1);

  setup();
}
