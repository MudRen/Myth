//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIC "碧水剑" NOR, ({ "bishui jian", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("no_paimai", 1);
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "剑身发出淡淡水色 锋利无比，相传出自一位无名铸剑师之手。\n");
                set("wield_msg","剑身如波，剑光似水，$n已握在$N手中，\n");
                set("unwield_msg", "$N将$n抽回腰间，华光顿敛。\n");
                                set("no_sell",1);
                                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
                }
        init_sword(150);
        setup();
}

