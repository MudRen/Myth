// sanjie tianyirest.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
����ҲҪ˯�������ο���Ҳ�������ɣ�����������͵��һ��
��Ϣ��ϢΪ�
LONG);

  set("exits", ([
  "south" : __DIR__"tianyilang5",
]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  set("sleep_room",1);
  set("if_bed",1);

  setup();
  replace_program(ROOM);
}
