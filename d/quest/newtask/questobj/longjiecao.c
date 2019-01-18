#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("Áú½á²Ý", ({ "longjie cao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿Å");
            set("long", "Ò»¿ÅÁú½á²Ý\n");
          }

    setup();
}
