// sanjie tianyidong3.c

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
  "north" : __DIR__"tianyidong5",
  "southwest" : __DIR__"tianyidong1",
]));
  set("outdoors", 0);

  setup();
}
