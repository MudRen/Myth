// sanjie tianmolu6.c

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
  "east" : __DIR__"tianmolu7",
  "southeast" : __DIR__"tianmolang1",
  "west" : __DIR__"tianmolu5",
]));
  set("outdoors", 1);

  setup();
}
