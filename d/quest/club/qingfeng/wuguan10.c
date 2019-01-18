inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","Çå·çÏ¸ÓêÂ¥¡ª¡ª·âÉñ°ñ");
  set ("long", CYN@LONG
LONG NOR);

  set("exits",([
//  "north" : "d/club/qingfeng/wuguan4",
  "south" : "d/club/qingfeng/wuguan9",
  ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
set("objects", ([ /* sizeof() == 1 */
         ]));
  setup();
}
