// sanjie tianyidong4.c

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
  "northeast" : __DIR__"tianyidong6",
  "south" : __DIR__"tianyidong2",
]));
  set("outdoors", 0);

  setup();
}
