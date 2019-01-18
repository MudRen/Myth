#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("“‰…Òµ§", ({ "yishen dan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "√∂");
            set("long", "“ª√∂“‰…Òµ§\n");
          }

    setup();
}
