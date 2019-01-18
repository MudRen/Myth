//°×´ó¹Ó

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"°×´ó¹Ó"NOR, ({ "cloth","baida gua" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "¼þ");
                set("value", 500);
                set("armor_prop/armor", 10);

        }
        setup();
}

