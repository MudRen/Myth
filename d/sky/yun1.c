//beitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "�ƺ�");
  set ("long", @LONG

�����Ǻ�嫵��ƺ�����ʲôҲ�����塣

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"yunlougate",
    "west" : __DIR__"dongtian",
  ]));

  setup();
}


