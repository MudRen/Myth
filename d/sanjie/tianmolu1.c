// sanjie tianmolu1.c

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
  "northeast" : __DIR__"tianmolu2",
  "southwest" : __DIR__"sanjiedao",
]));
  set("outdoors", 1);

  setup();
}
