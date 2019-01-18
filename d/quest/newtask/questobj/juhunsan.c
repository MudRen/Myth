#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("×ÓÎç¾Ğ»êÉ¢", ({ "juhunsan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Æ¿");
            set("long", "Ò»Æ¿×ÓÎç¾Ğ»êÉ¢\n");
          }

    setup();
}
