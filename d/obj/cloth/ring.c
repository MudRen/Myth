#include <armor.h>

inherit FINGER;

void create()
{
        set_name("��ָ", ({ "ring" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "gold");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

