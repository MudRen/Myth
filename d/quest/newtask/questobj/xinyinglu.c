#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【菩提心影录】", ({ "xinyinglu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "又名《少林五绝相克论证》，少林寺前辈高人菩提上人所著武籍。\n");
          }

    setup();
}
