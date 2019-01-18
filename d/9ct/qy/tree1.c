// 九重天 傲野天 by Calvin

#include <ansi.h>
inherit "/d/9ct/qy/tree.c";

void falldown(object,object);
void create()
{
        set("short", HIW"傲野天"NOR);
  set ("long", @LONG

          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※
          ※莫过天涯胜此处  依雪逍遥域仙羡※
          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※

LONG);

        set("exits", ([
  "down": __DIR__"yi",
        ]));

        set("objects", ([
                 "/d/9ct/obj/lingzi.c" : 1,
              ]));

        setup();
}
