#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("Ö½ÒÂ", ({ "zhiyi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 3);
               }
        setup();
}
