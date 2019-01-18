// goldring.c ½ð½äÖ¸

#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIW"ÈáË¿"NOR, ({ "sea" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 2000);
                set("material", "gold");
                set("armor_prop/armor", 60);
        }
        setup();
}       
