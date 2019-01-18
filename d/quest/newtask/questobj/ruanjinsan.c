#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(" Æœ„»ÌΩÓ…¢", ({ "ruanjin san" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "∆ø");
            set("long", "“ª∆ø Æœ„»ÌΩÓ…¢\n");
          }

    setup();
}
