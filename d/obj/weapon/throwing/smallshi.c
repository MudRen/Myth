//Cracked by Roath
// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("ʯ��", ({"shi kuai", "shi", "stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
		set("long","һ��Сʯͷ��");
                set("base_unit", "��");
                set("base_weight", 1000);
        }
        set_amount(random(10)+5);
        init_throwing(5);
        setup();
}

