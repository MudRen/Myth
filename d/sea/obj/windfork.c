//风音叉
//by wuyou

#include <weapon.h>
//  inherit F_UNIQUE;

inherit FORK;
#include <ansi.h>
void create()
{
        set_name(HIB"风音叉"NOR, ({"wind fork","fork","cha"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","碧波闪闪,风音瑟瑟,让人看去就想起浩瀚无边的大海,似乎它里面隐藏着东海的秘密！\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",HIW "$N仰天一声龙吟,一柄海蓝色的飞叉从天而降,落如手中！\n"NOR);
                set("unwield_msg",HIW "$N随手一甩,手中的风音叉“嗖”的一声脱手而出,飞向天际...\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_fork(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "东海龙宫"
                && me->query_skill("fengbo-cha",1) > 1)
    damage_bonus = me->query_skill("fengbo-cha",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIW"风音叉发出阵阵音波！\n" NOR;

}

