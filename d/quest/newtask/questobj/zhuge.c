#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("Öñ¸ë", ({ "zhu ge" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ö»");
            set("material", "bamboo");
            set("long", "Ò»Ö»Öñ¸ë\n");
          }

    setup();
}
