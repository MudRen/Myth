#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("如拉", ({ "ru la" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "只");
            set("long", "一只如拉\n");
          }

    setup();
}
