#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"Å®¶ùºì"NOR, ({ "nverhong" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Æ¿");
            set("long", "Ò»Æ¿Å®¶ùºì\n");
          }

    setup();
}
