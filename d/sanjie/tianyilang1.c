// sanjie tianyilang1.c

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
  "north" : __DIR__"tianyidian4",
  "west" : __DIR__"tianyiting1",
  "east" : __DIR__"tianyiting2",
  "south" : __DIR__"tianyidian1",
]));
  set("outdoors", 1);

  setup();
}
