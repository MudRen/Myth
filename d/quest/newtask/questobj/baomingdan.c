#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�廢������", ({ "baomingdan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ö");
            set("long", "һö�廢������\n");
          }

    setup();
}
