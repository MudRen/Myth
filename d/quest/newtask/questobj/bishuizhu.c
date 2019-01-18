#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("±‹ÀÆ÷È", ({ "bishui zhu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ø≈");
            set("long", "“ªø≈±‹ÀÆ÷È\n");
          }

    setup();
}
