// ������ָ by Calvin

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW"������ָ"NOR, ({ "yinyang jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 0);
                set("material", "gold");
                set("armor_prop/armor", 100);
                set("armor_prop/spells", 100);
        }
        setup();
}       
