#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("»¹Ñô²¹Ñªµ¤", ({ "buxue dan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ã¶");
            set("long", "Ò»Ã¶»¹Ñô²¹Ñªµ¤\n");
          }

    setup();
}
