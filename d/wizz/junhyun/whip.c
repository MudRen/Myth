//银索金铃
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIW"银索"+HIY"金铃"NOR, ({"yinsuo jinling", "bian","whip"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一条用天蚕丝制成的银索上挂着两个金色的铃铛。\n");
                set("unit", "条");
                set("value", 12000);
                set("wield_msg",HIW "伴随着一阵铃声$N手里已经多了一条白晃晃的银索\n"NOR);
                set("unwield_msg", "$N将金铃索缠在手腕上。\n");
                set("weapon_prop/courage", 20);
                }
        init_whip(100);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "盘丝洞"
                && me->query_skill("yinsuo-jinling",1) > 1)
    damage_bonus = me->query_skill("yinsuo-jinling",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIW"银索"+HIY"金铃"+HIC"上霞光四射！\n" NOR;

}

