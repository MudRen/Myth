#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIB"ˮ������"NOR);
set ("long", @LONG

ˮ�У���һ���巢�������Ĺ�â��

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/bingfo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
