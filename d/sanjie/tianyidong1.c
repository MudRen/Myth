// sanjie tianyidong1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
һ���ڲ�¡����ɽ����ʲô������������ɭ�ֲ�������׳��
��ǰ���߿���ʲô������
LONG);

  set("exits", ([ 
  "northwest" : __DIR__"tianyidong2",
  "northeast" : __DIR__"tianyidong3",
  "south" : __DIR__"tianyilu9",
]));
  set("outdoors", 0);

  setup();
}
