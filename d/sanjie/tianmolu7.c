// sanjie tianmolu7.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
	
�������죬·�ϲ�ʱ���������˹��޹ǣ����ùǶ�Ҳ�м�����
����������ɽ�ϣ���������Χ�ţ������ĺ����Һû�����һ
����ѹ����������Ȼ�������϶����ҡ�
LONG);

  set("exits", ([
  "east" : __DIR__"tianmolu8",
  "northwest" : __DIR__"tianmolang2",
  "west" : __DIR__"tianmolu6",
]));
  set("outdoors", 1);

  setup();
}
