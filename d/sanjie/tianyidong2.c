// sanjie tianyidong2.c

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
  "north" : __DIR__"tianyidong4",
  "southeast" : __DIR__"tianyidong1",
]));
  set("outdoors", 0);

  setup();
}
