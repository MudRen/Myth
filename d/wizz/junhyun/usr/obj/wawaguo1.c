//sea.c player装备
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit FINGER;


void create()
{
        set_name(HIW"人参果"NOR, ({ "wawaguo", "ring" }) );
        set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/spells", 50);
                set("armor_prop/dodge", 20);
                set("value", 50000);
        }
        setup();
}

