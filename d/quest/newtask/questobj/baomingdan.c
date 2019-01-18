#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("Îå»¢±£Ãüµ¤", ({ "baomingdan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ã¶");
            set("long", "Ò»Ã¶Îå»¢±¦Ãüµ¤\n");
          }

    setup();
}
