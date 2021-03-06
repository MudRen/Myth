#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int hellfirewhip,tonsillit,gouhunshu,times,extra,damage;
        string desc_msg="";
        int bellicosity_num,lhb_level;
        
        hellfirewhip = (int)me->query_skill("hellfire-whip", 1);
        tonsillit = (int)me->query_skill("tonsillit", 1);
        gouhunshu = (int)me->query_skill("gouhunshu", 1);
        damage=hellfirewhip;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「追魂夺魄」？\n");

        if(!me->is_fighting())
                return notify_fail("「追魂夺魄」只能在战斗中使用！\n");
        
        bellicosity_num = (int)me->query("bellicosity");
        
        if( hellfirewhip < 80)
                return notify_fail("你的烈火鞭级别还不够，无法领悟魂魄的真意！\n");

        if (!PFM_D->valid_family(me, "阎罗地府"))
                return notify_fail("[追魂夺魄]是追魂夺魄不传之密！\n");
        
        if( tonsillit < 80)
                return notify_fail("你的摄气决修为不够，无法动人心神！\n");
        
        if( gouhunshu < 80)
                return notify_fail("你的勾魂术级别还不够，无法勾人魂魄！\n");
                
        if (bellicosity_num<(tonsillit+gouhunshu)) 
                return notify_fail("你杀气不够，想到吸食魂魄不由的瑟瑟发抖!");
              
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");
        
        if((int)me->query("kee") < 300 || (int)me->query("sen") <300)
                return notify_fail("先照顾好你自己的魂魄吧！\n");

                
        if( time()-(int)me->query_temp("zhdp_end") < 3 )
                return notify_fail("绝招用多就不灵了！\n");
          
        message_vision(HIC"\n$N突然满面黑气，眼中青光晃动，嘴中长出四个獠牙，手中鞭显出无数冤魂环绕，
  阴风习习，使出了烈火鞭失传已久的绝学**追魂夺魄**。\n"NOR,me);
        extra=(int)(bellicosity_num/30);
        me->add_temp("apply/attack", hellfirewhip+extra);
        me->add_temp("apply/damage", hellfirewhip+extra);
        if(!target->is_busy())
                target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/attack", -(hellfirewhip+extra));
        me->add_temp("apply/damage", -(hellfirewhip+extra));
        if( hellfirewhip > 120 && tonsillit > 120 && gouhunshu > 120 )
        {   
                message_vision(HIR"\n$N想起地狱中的烈火，不由的热血上涌，拼命打出一鞭。\n"NOR,me);
 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                message_vision(HIR"\n$N鞭法似乎已经走老，突然鞭头喷出一道烈火，$n无论如何也躲不过去了。\n"NOR,me,target);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");

        }
        if( hellfirewhip > 160 && tonsillit > 160 && gouhunshu > 160 )
        {    
                message_vision(HIR"\n$N仿佛见到无数魂魄缭绕在你的周围，一丝冷笑，大喝一声，烈火鞭中
           的精髓在这一式中尽现。\n"NOR,me);
                me->add_temp("apply/attack",hellfirewhip*2+extra);
                me->add_temp("apply/damage",hellfirewhip*2+extra);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                me->add_temp("apply/attack",-(hellfirewhip*2+extra));
                me->add_temp("apply/damage",-(hellfirewhip*2+extra));
                target->receive_damage("kee",damage,me,"pfm"); 
                target->receive_damage("sen",damage,me,"pfm"); 
                target->receive_wound("sen",damage/2,me,"pfm"); 
                target->receive_wound("kee",damage,me,"pfm"); 
        }
           
        message_vision(HIR"\n$N双目青光闪烁，冷冷道： 魂魄已去，还不束手就缚！。\n"NOR,me);
        if ((bellicosity_num/3*2)<random(((int)target->query("max_mana")+(int)target->query("max_force") )/3))
        {
                message_vision(HIR"\n对方抱元守一，丝毫不为所动！。\n"NOR);
//                me->start_buzy(2);
        }   
        else 
        {   
                message_vision(HIC"\n$N话语刚落，$n魂飞魄散，呆立当场!\n"NOR,me,target);

                target->start_busy(3+random(3));

        }
                                
 
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("zhdp_end",time());
        return 1;
}

