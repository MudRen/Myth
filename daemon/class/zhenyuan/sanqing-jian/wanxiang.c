//Created by Wuyou@Sanjie

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp, size, num, extra, i;
        object weapon;
        weapon = me->query_temp("weapon");
        extra=(int)me->query_skill("sanqing-jian", 1);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"你要对谁施展"RED"“包罗万象”"WHT"？\n"NOR);
        if( !me->is_fighting(target) )
                return notify_fail(RED"“包罗万象”"WHT"只能在战斗使用。\n"NOR);
        if (!PFM_D->valid_family(me, "五庄观"))
                return notify_fail(RED"“包罗万象”"WHT"是五庄观绝技！\n");                        
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail(WHT"只有用镇元神功才能运用"RED"“包罗万象”"WHT"。\n"NOR);
        if (me->query_skill("sanqing-jian",1)<100)
                return notify_fail(WHT"你的三清剑法不够纯熟，还得继续努力。\n"NOR);     
        if (me->query_skill("zhenyuan-force",1)<100)
                return notify_fail(WHT"你的镇元神功不够纯熟，还得继续努力。\n"NOR);
        if (me->query_skill("taiyi",1)<100)
                return notify_fail(WHT"你的太乙仙法不够纯熟，还得继续努力。\n"NOR);                                          
        if (me->query_skill("baguazhen",1)<100)
                return notify_fail(WHT"你的八卦阵法不够纯熟，还得继续努力。\n"NOR);                     
        if((int)me->query("force") < 300 )
                return notify_fail(WHT"你的内力不足。\n"NOR);
        if( me->query("max_force") < 1000 )
                return notify_fail(WHT"你的内力修为甚浅，不足以用"RED"「包罗万象」"WHT"。\n"NOR);  
        if( me->query("max_mana") < 1000 )
                return notify_fail(WHT"你的法力修为甚浅，不足以用"RED"「包罗万象」"WHT"。\n"NOR);                                        
        if( (int)me->query("kee") < 200 || (int)me->query("sen") < 200  )
                return notify_fail(WHT"你身体太虚弱了，无法施展"RED"「包罗万象」"WHT"！\n"NOR);
        if( time()-(int)me->query_temp("wanxiang_end") < 4 ) 
                return notify_fail(WHT"你现在内息尚未平复，再用此绝技恐有损元气！\n"NOR); 
                                
        msg = HIY "\n$N将"HIR"太乙仙法"HIY"发挥至极限，周身顿时仙雾缭绕。$N的双袖越变越大，铺天盖地的罩向$n。\n"
             +"$n向$N的双袖望去，只见里面星罗密布，斗转星移，好似"HIW"无穷的宇宙"HIY"一般。\n" NOR,
      
        me->add("sen", -50);
        me->add("kee", -50);
        me->add("force", -50);
        ap =(int)me->query_skill("sanqing-jian", 1)+(int)me->query_skill("taiyi", 1);
        damage=ap*ap/300;
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("spells");
        dp = dp * dp * dp /10;   
        dp = dp + (int)target->query("combat_exp");
        if( random(7000*ap/dp) <  20 ) 
        {
                msg += HIW "$n晓得"HIY"五庄观"HIR"太乙仙法"HIW"中的"HIC"“袖里乾坤”"HIW"不同凡响，急忙移形换位，飘然后退。"
                    +"$N的双袖落空，自叹修为尚浅！\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else if( random(7000*ap/dp) <  40 ) 
        {
                msg += HIY "$n躲闪不及，反而上前迎击，结果被$N的双袖扫中头部，顿时头痛欲裂，眼冒金星。\n"NOR;
                message_combatd(msg, me, target, "");
                target->receive_damage("kee",damage/2,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                COMBAT_D->report_status(target); 
                if(!target->is_busy()) 
                        target->start_busy(random(2));
        } 
        else 
        {
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");
                msg += HIW "$n迷茫的望着"HIR"虚幻的日月星辰"HIW"，被$N的双袖罩个正着，立即浑身不能动弹，陷入一片漆黑之中。\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                target->start_busy(3+random(3));

        }

        if (me->query_skill("sanqing-jian",1)>119)
        {
                
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra);            
/*              
                mapping dao= ([
                "damage": 200,
                "dodge" : -10,
                "parry" : -10,
                "damage_type" : "刺伤",
                "action" :  MAG"$N狂喝一声，使出一招"HIM"「绝域苍茫」"MAG"，双手紧握$w
带着逼人的杀气，刺向$n的$l",
                ]);
                
                me->set("actions",dao); 
*/              
                msg = WHT "          ～～～化剑为刀～～～\n"NOR;        
                msg += WHT "$N舞动手中"+weapon->name()+
     WHT"，以剑化刀，使出"HIR"雁歌刀法"WHT"，怪招迭出，把对手看得眼花缭乱，目瞪口呆！\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));      
/*              
                me->reset_action();
                
                mapping chui= ([
                "damage": 200,
                "dodge" : -10,
                "parry" : -10,
                "damage_type" : "刺伤",
                "action" :  HIC"$N使出了一招"HIG"「五丁开山」"HIC"，手中的$w举重若轻，势若疯虎地向$n$l连连砸去",
                ]);
                
                me->set("actions",chui);        
*/              
                msg = HIY "          ～～～化剑为锤～～～\n"NOR;        
                msg += HIY "$N舞动手中"+weapon->name()+
     HIY"，以剑化锤，使出"HIR"开山锤法"HIY"，怪招迭出，把对手看得眼花缭乱，目瞪口呆！\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));      
/*
                me->reset_action();
                
                mapping zhang= ([
                "damage": 200,
                "dodge" : -10,
                "parry" : -10,
                "damage_type" : "刺伤",
                "action" :  HIW"$N使出一招"HIY"「群魔伏首」"HIW"，手中的$w带出飞沙走石般的杖风压向$n的$l",
                ]);
                
                me->set("actions",zhang);       
*/              
                msg = HIG "          ～～～化剑为杖～～～\n"NOR;        
                msg += HIG "$N舞动手中"+weapon->name()+
     HIG"，以剑化杖，使出"HIW"伏魔杖法"HIG"，怪招迭出，把对手看得眼花缭乱，目瞪口呆！\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));      
//              me->reset_action();             
                
                
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra); 
        }
        
        if (me->query_skill("sanqing-jian",1)>149)
        {
                msg = HIR "$N口中念道：“"HIY"天地轮回，星宿轮转，五行归位，万象归一！"HIR"”\n"NOR;
                msg += HIR "$N双袖之中突然爆射出无数"HIY"星屑"HIR"，径直奔向$n。\n"NOR;
                
                me->add("force",150);
                if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
                {       
                        msg += HIR "这些"HIY"星屑"HIR"将$n包罗其中，$n被打的面目全非。\n"NOR;
                        message_combatd(msg, me, target, "");
                        size=(int)(me->query_skill("sanqing-jian")/5);
                        damage=random(size)+size;
                        damage=damage+me->query_str()+random(me->query_temp("apply/damage"));
                        num=size/5+random(size/5);
                        for(i=0;i<=num;i++)
                        {
                                target->receive_damage("kee",damage,me,"pfm");
                                target->receive_wound("kee",damage,me,"pfm");
                        }
                        COMBAT_D->report_status(target);                
                }
                else
                {
                        msg += HIY "$n疯狂的后退躲闪，并且用力挥舞兵刃，以阻止星屑的侵入。\n"NOR;
                        message_combatd(msg, me, target, "");
                }
        }
                
        me->set_temp("wanxiang_end",time());
        return 1;
}


