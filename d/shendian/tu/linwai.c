#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"ʯ����"NOR);
set ("long", @LONG

�����и�ʯ̨�������ƺ���ʲô������

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/shendian/shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
   "/d/shendian/obj/shifo" : 1,
  ]));
  set("no_clean_up", 1);
  setup();
}
