// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIG "�಼Ь" NOR, ({ "xie", "shoes" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ˫���±��ɵĲݱ貼Ь��  \n");
                set("material", "cloth");
                set("unit", "˫");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 5);
                set("female_only", 1);
        }
        setup();
}
