// 九重天 楼兰天 by Calvin

#include <ansi.h>
inherit "/d/9ct/qy/tree.c";

void falldown(object,object);
void create()
{
        set("short", CYN"四重·楼兰天"NOR);
  set ("long", @LONG

          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※
          ※紫木青楼兰花处  香飘引客提木子※
          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※

LONG);

        set("exits", ([
  "down": __DIR__"si",
        ]));

        set("objects", ([
              "/d/9ct/obj/tizi.c" : 1,
              ]));

        setup();
}
