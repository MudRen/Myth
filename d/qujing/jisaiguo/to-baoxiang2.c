#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

������ȥ��һ����ĳǳأ���ֱ����·ֱͨ����У������ͽ��
��·���������������ɼ�����֮������������·�򶫱��������죬
��������һ��Сɽ֮��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"to-baoxiang1",
  "east" : __DIR__"to-baoxiang3",
]));

  setup();
}

