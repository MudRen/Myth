//by dewbaby@sk_sjsh
//lingbojian.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;

inherit SWORD;

void create()
{
    set_name(HIG"凌波剑"NOR,({"lingbo jian","lingbo","jian"}));
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","柄");
                set("value",120000);
                set("no_drop","1");
                set("material","gold");
                set("long",HIG"据说这是凌波仙子的神剑，它周身闪烁着碧绿的光芒。\n"NOR);
                set("wield_msg",HIG"时光如梭，花草凋零，$N已将$n握在手中，你心中一寒。\n"NOR);
                set("unwield_msg",HIG"$N双眼微闭，眨眼间已将$n插回腰间。你只觉周身冰凉。\n");
                      set("no_drop","1");
                      set("no_sell","1");         
     }
    init_sword(130);
    setup();
}


