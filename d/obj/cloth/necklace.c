#include <armor.h>

inherit NECK;

void create()
{
        set_name("����", ({ "necklace" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "pearl");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

