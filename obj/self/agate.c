//Last modified by aeddy@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIR "Âêè§" NOR, ({ "agate" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	       set("long", HIR "Ò»¿é¾§Ó¨ÌÞÍ¸µÄ°µºìÉ«Âêè§¡£\n" NOR);
              set("value", 50000);
		set("unit", "¿é");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
              set("magic/type", "fire");
              set("magic/power", 100);
	}
        setup();
}

