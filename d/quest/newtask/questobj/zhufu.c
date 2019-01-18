#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"ÂÌÓñÖñ·û"NOR, ({ "lvyu zhufu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ö»");
            set("long", "Ò»Ö»ÂÌÓñÖñ·û\n");
          }

    setup();
}
