// sanjie langerdian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�˶���");
  set ("long", @LONG
	
һ��С�꣬�ṩ�˻����ķ��񡣵���ֻ��һ�����˼Ҵ���
��������ͣ�ɾ��ģ��лص��ҵĸо���
LONG);

  set("exits", ([
  "west" : __DIR__"sanjiedao",
]));
  set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/guanjia": 1 ]) );

  setup();
  replace_program(ROOM);
  "/obj/board/sjsboard"->foo();
}
