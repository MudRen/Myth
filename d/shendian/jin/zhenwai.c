#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIY"������"NOR);
set ("long", @LONG

������ʲô�����������⣬ԭ����һ����

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/jinfo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
