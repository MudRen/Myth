// 九重天 灵佛天 by Calvin

#include <ansi.h>
inherit "/d/9ct/qy/tree.c";

void falldown(object,object);
void create()
{
        set("short", HIY"九重·灵佛天"NOR);
  set ("long", @LONG

          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※
          ※※道语悟※※佛心悟※※仙缘悟※※
          ※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※

LONG);

        set("exits", ([
  "down": __DIR__"jiu",
        ]));

        set("objects", ([
            "/d/9ct/obj/fxd.c" : 1, 
              ]));

        setup();
}
