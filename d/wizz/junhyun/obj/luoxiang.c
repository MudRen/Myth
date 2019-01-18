//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( RED "罗翔剑" NOR, ({ "luoxiang jian", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("no_paimai", 1);
                set("value",200);
//              set("no_drop", "1");
                set("weapon_prop/intelligence", 15);
                set("material", "iron");
                set("long", "一柄木剑，剑身散发着淡淡的幽香，让人心神为之一振。\n");
                set("wield_msg","$n泛起一道红光，落入$N的手中！\n");
                set("unwield_msg", "$N将$n小心的放入鞘中，华光顿敛。\n");
                                set("no_sell",1);
                                set("no_get","这个你可拣不起来哦!\n");
                }
        init_sword(1);
        setup();
}

