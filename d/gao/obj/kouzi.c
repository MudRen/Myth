// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����", ({"kouzi"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һöС����");
                set("unit", "Щ");
                set("base_unit", "ö");
                set("base_weight", 40);
		set("base_value", 1);
        }
	set_amount(1);
        init_throwing(20);
        setup();
}

