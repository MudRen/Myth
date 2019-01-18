#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"ÂÌÓñ·ğ"NOR, ({ "lvyu fo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ö»");
            set("long", "Ò»Ö»ÂÌÓñ·ğ\n");
          }

    setup();
}
