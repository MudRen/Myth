#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIR"���Ҷ���"NOR);
set ("long", @LONG

������һ����С�ļ�̳���������һ����

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/d/shendian/obj/huofo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
