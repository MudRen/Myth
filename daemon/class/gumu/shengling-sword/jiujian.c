#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("shengling-sword",1);

        if (!PFM_D->valid_family(me, "轩辕古墓"))
                return notify_fail("［九剑妖魂］只有轩辕古墓弟子才可以使用！\n");

        if ( extra < 200) return notify_fail("你的圣灵剑法还不够纯熟！\n");     
       
        if( (int)me->query("force") < 800 )      
                return notify_fail("你的内力不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九剑妖魂］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        me->add("force", -300);
        weapon = me->query_temp("weapon");
        if(!target->is_busy()) target->start_busy(2);
        message_vision(RED  "\n\n$N腾空跃起，变换身形，瞬移北斗七星位，手中的"+ weapon->name() +RED"划出森然剑气，剑剑逼向$n ！\n\n" NOR, me, target);
        message_vision(HIC  "「妖气冲天」，$N手中"+ weapon->name() +HIC"带着一阵寒意直刺$n！" NOR, me, target);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n「魂飞魄散」，$N手中"+ weapon->name() +HIR"带着冷冷的剑气斜刺$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n「妖兽噬天」，$N手中"+ weapon->name() +HIY"落叶般横扫$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n「十万神魔」，$N手中"+ weapon->name() +HIW"闪电般猛劈$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(MAG  "\n「群魔乱舞」，$N手中"+ weapon->name() +MAG"携阵阵妖气直扑$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n「妖极天世」，$N手中"+ weapon->name() +HIY"迅雷般刺向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG  "\n「鬼魅人间」，$N手中"+ weapon->name() +HIG"猛然化为一团紫气冲向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC  "\n「魔影幢幢」，$N手中"+ weapon->name() +HIC"随道道寒光飞向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "\n「魔光魅影」，$N手中"+ weapon->name() +HIM"化为万千幻影刺向$n！" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(RED  "\n$N收剑后退，手中"+ weapon->name() +RED"还缠绕着阵阵妖魂,好一招"+HIW"“九剑妖魂”！" NOR, me, target);
        me->start_busy(2);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        return 1;
}

