// sanjie tianyiting1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
��������һ������ƽ����͵ĵط��������˱ǣ���֪���õ�
��ʲô��Ҷ����Ȼ����һյ����������������������
LONG);

  set("exits", ([
  "west" : __DIR__"tianyilang2",
  "east" : __DIR__"tianyilang1",
]));
  set("outdoors", 0);

  setup();
}
