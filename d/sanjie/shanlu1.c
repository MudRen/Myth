// sanjie shanlu1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
	
�߽������￴���Ĵ�Ұ�ݴ��������Ĺֲݹֻ��а���˸ߣ�
ǰ����һ�������ƶ˵Ĵ�ɽ������֪��ǰ�������ַ�
LONG);

  set("exits", ([
  "northup" : __DIR__"shanlu2",
  "southdown" : __DIR__"wujiang5",
]));
  set("outdoors", 1);

  setup();
}
