// jadesword.c

#include <weapon.h>
inherit SWORD;
#include <ansi.h>

void create()
{
        set_name(HIG"碧玉箫"NOR, ({ "jadesword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支镶满碧玉的长箫");
                set("value", 20000);
                set("material", "steel");
        }
        init_sword(130);

        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");

        setup();
}

