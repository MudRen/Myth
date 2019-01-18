#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"ºìË¿½í"NOR, ({ "hongsijin" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ï®");
            set("material", "silk");
            set("long", "Ò»Ï®ºìË¿½í\n");
          }

    setup();
}
