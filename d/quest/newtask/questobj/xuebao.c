#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("地龙血宝", ({ "dilong xuebao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "只");
            set("long", "一只地龙血宝\n");
          }

    setup();
}
