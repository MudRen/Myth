#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"天山雪莲"NOR, ({ "tianshan xuelian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "颗");
            set("long", "一颗天山雪莲\n");
          }

    setup();
}
