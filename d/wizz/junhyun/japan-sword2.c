//长曾弥·虎彻
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "长曾弥·虎彻" NOR, ({ "changzengmi huche", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "胁差，刃长45.75CM。越前国刀工虎彻于宽文三年所作。
为新撰组剑士近藤勇的爱刀。刀铭：长曽袮虎彻入道兴里\n");
                set("wield_msg","$N从腰间抽出一柄剑，划出一个弧形，一股剑气扑面袭来\n");
                set("unwield_msg", "$N将$n收回腰间，长长的出了口气。\n");
                                set("no_sell",1);
                                set("no_get","好孩子是不会随便拿别人的东西的哦。\n");
                }
        init_sword(200);
        setup();
}

