#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ƥ��", ({"pipao"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 800);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

