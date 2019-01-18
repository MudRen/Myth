//正宗
//by junhyun@SK
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIW "名物观世·正宗" NOR, ({ "zhengzong", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100000);
//              set("no_drop", "1");
                set("material", "iron");
                set("long", "刀，刃长64.4CM。相州名刀工正宗作于镰仓末期，战国时为
石田三成所有，关原合战后被敬献给德川家康。刀的全称为名物观世正宗。\n");
                set("wield_msg","$N从腰间抽出一柄剑，划出一个弧形，一股剑气扑面袭来\n");
                set("unwield_msg", "$N将$n收回腰间，长长的出了口气。\n");
                                set("no_sell",1);
                                set("no_get","好孩子是不会随便拿别人的东西的哦。\n");
                }
        init_sword(200);
        setup();
}

