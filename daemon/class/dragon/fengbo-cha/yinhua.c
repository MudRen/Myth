//BY Cigar 2002.01 yinhua.c [吟花一笑]
#include <ansi.h>

#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "fork")
                return notify_fail(MAG"开什么玩笑，没装备就想使「东海吟花笑」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「海边吟花一笑」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("dragonforce", 1) < 100 )
                return notify_fail("你的特殊内功不够娴熟，不会使用。\n");
        if ((int)me->query_skill("fengbo-cha",1) < 100 )
                return notify_fail(WHT"你的风波叉不够娴熟，还使不出「海边吟花一笑」。\n"NOR);
        if ((int)me->query("max_force")<1000)
                return notify_fail(RED"你的内力修为不足，无法运足「海边吟花一笑」的内力。\n"NOR);
        if( time()-(int)me->query_temp("yinhua_end") < 3 )  
                return notify_fail(WHT"「吟花一笑」对真气损耗太大,无法连续使用！\n"NOR); 
        if(time()-me->query_temp("lxtx_end")<3)
                return notify_fail(WHT"「吟花一笑」"NOR"与"HIY"乱舞"NOR"无法连续使用！\n"NOR);                 
        if ((int)me->query("force")<500)        
                return notify_fail(HIC"你现在内力不够，没能将「东海吟花一笑」使完！\n"NOR);
        
        msg = HIY "$N眼望水晶宫窗儿外，深谷幽处的千花百草，心有怜惜"+BLINK""HIR"§吟花一笑§\n"NOR;
        msg += HIG"玉肌翠袖，冰葩淡不妆，一只云髻人宜，刻玉雕琼作小葩。\n"NOR;
        msg += HIG"便舞春风，无情犹感会，一段冰壶剪就，西风偷得余香去。\n"NOR;
        msg += HIG"烛光花影，花枝红裹烛，珠星碧月彩云，人间别有几春风。\n"NOR;
        msg += HIC"昨夜雨疏，浓睡消残酒，胭脂谁与匀淡，香雾空蒙月转，试问眷恋人，知否？知否？\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                //me->start_busy(2);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("fork", 1);
                damage = damage + random(damage);
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage, me, "pfm");
                target->receive_damage("sen", damage, me, "pfm");
                target->receive_wound("sen", damage/3, me, "pfm");
                msg += HIM"$n心旷神怡，手中玉酿美酒随之坠落，破碎之声惊醒$n的春阁一梦，顿觉心乱如麻。\n"NOR;
                msg += HIM"$N的"+HIR"§吟花一笑§"+HIM"早已惊散了$n的三魂六魄......\n"NOR;
                target->apply_condition("flower",5+random(5) + target->query_condition("flower"));
                me->add("force", -200);
        } 
        else
        {
                //me->start_busy(2);
                msg += HIW"可是$n欣喜若狂，侧身轻跃，站在$N一旁，手持玉酿美酒小酌，欣赏此情此景。\n"NOR;
                msg += HIW"$N心中直觉郁闷无比，见欣赏才情此景的人竟是泛泛之辈，也无心吟花了。\n"NOR;
                me->add("force", -150);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        me->set_temp("yinhua_end",time());
        return 1;
}


