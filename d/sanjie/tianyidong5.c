// sanjie tianyidong5.c

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
  "northwest" : __DIR__"tianyidong6",
  "south" : __DIR__"tianyidong3",
]));
  set("outdoors", 0);

  setup();
}
