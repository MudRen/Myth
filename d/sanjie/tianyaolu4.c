// sanjie tianyaolu4.c

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
  "northwest" : __DIR__"tianyaolu5",
  "southeast" : __DIR__"tianyaolu3",
]));
  set("outdoors", 1);

  setup();
}
