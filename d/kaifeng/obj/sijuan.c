#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("͸��˿��", ({ "si juan", "si", "juan" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "silk");
		set("value", 1000);
                set("armor_prop/dodge", 1);
        }
        setup();
}

