// goldring.c 金戒指

#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIC"毛主席语录"NOR, ({ "whip", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 2000);
                set("material", "gold");
                set("armor_prop/armor", 60);
        }
        setup();
}       
