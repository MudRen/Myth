#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIG"������"NOR);
set ("long", @LONG

��Լ�У������м俴��ʲô������

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/mufo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
