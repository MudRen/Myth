//雷光锏
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit MACE;
#include <ansi.h>
void create()
{
        set_name(HIC"雷光锏"NOR, ({"leiguang mace","mace","bian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","天地造就的神器，你仿佛能从锏上听到滚滚雷声。\n");
                set("unit", "条");
                set("value", 12000);
                set("wield_msg",HIW "$N从背后抽出一柄锏，霎时间雷声滚滚，天地为之色变。\n"NOR);
                set("unwield_msg",HIW "$N微微一笑,手中的月轮剑“嗖”的一声脱手而出,飞向天际...\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_mace(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "将军府"
                && me->query_skill("jinglei-mace",1) > 1)
    damage_bonus = me->query_skill("jinglei-mace",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIB"雷光锏上雷声滚滚。\n" NOR;

}

