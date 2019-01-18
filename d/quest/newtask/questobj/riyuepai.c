#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ÈÕÔÂÅÆ", ({ "riyue pai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿é");
            set("material", "stone");
            set("long", "Ò»¿éÑª¼£°ß°ßµÄÁîÅÆ¡£\n");
}
    setup();
}
