//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIG "ôä´ä" NOR, ({ "jade" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIG "Ò»¿é±ÌÍ¸ÓûµÎµÄôä´ä¡£\n" NOR);
                set("value", 50000);
		    set("unit", "¿é");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "cold");
                set("magic/power", 100);
	}
        setup();
}
