//Last modified by waiwai@2001/04/15 

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(CYN"»Ò½ý"NOR, ({ "ash" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶Ñ");
                set("no_get",1);
                set("long", "Ò»¶Ñ´ø×ÅÓà»ðµÄ»Ò½ý¡£\n");
                set("value", 50);
        }
}


