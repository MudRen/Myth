#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ÎÚ·ç²Ý", ({ "wufeng cao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿Å");
            set("long", "Ò»¿ÅÎÚ·ç²Ý\n");
          }

    setup();
}
