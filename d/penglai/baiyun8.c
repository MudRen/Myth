//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "���ƶ�");
  set ("long", @LONG

������С������ȴ������ء�
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northeast": __DIR__"baiyun"+sprintf("%d",random(20)),
  "north": __DIR__"baiyun"+sprintf("%d",random(20)),
  "northwest": __DIR__"baiyun9",
]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}

