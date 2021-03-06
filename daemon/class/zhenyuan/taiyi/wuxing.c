#include <ansi.h>

inherit SSERVER;
void doblow(object);
int random_go(object victim,string* dirs);

int cast(object me, object target)
{
        string msg,start;
        int busy_time, ap, dp ,msgnum ,damage;


        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("你要对谁施展这个法术？\n");

        if ( !me->is_fighting() )
                return notify_fail("这个法术只能在战斗中使用！\n");

        if (!PFM_D->valid_family(me, "五庄观"))
                return notify_fail("你非五庄观弟子，怎能使用五行法术？\n");  


        if((int)me->query_skill("spells") < 60)
                return notify_fail("你还没学会五行遁法。。。\n");

        if((int)me->query_skill("baguazhen",1) < 30)
                return notify_fail("你对五行八卦还不够了解，这样使用会有危险。。。\n"); 


        if ( target == me ) {

                if((int)me->query("mana") < 100 )
                        return notify_fail("你的法力不够！\n");
                if((int)me->query("sen") < 100 )
                        return notify_fail("你的精神没有办法有效集中！\n");
                me->add("mana", -100);
                me->receive_damage("sen", 10);

                if( random(me->query_skill("spells")) < 20 ) {
                        
                        write("你失败了。\n");
                        return 1;
                }
        msgnum = random(5);
        switch ( msgnum ) {
        case 0:
            msg = WHT "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一道黑气，无影无踪地消失了！\n\n"NOR ;
            break ;
        case 1:
            msg = HIY "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一道金光，嗖地一声飞走了！\n\n"NOR ;
            break ;
        case 2:
            msg = HIR "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一团火焰，然后消失得无影无踪！\n\n"NOR ;
            break ;
        case 3:
            msg = HIG "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一段枯木，真身已不知去向！\n\n"NOR ;
            break ;
        case 4:
            msg = BLU "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
            "只见$N化作一团大雾，不知飘到哪里去了！\n\n"NOR ;
            break ;
        }

        message_vision(msg, me);


        switch ( msgnum ) {
        case 0:
            start="/d/death/gate";
            message("vision", WHT+me->name()+"的身影在一团黑气中凝结成形。\n"NOR,
              environment(me), me);
            tell_object(me, WHT"你的身影突然出现在一团黑气中。\n"NOR);
            break ;
        case 1:
            start="/d/city/kezhan";
            message("vision", HIY+me->name()+"突然从一道金光中跳了出来。\n"NOR,
              environment(me), me);
            tell_object(me, HIY"你的身影突然出现在一道金光中。\n"NOR);
            break ;
        case 2:
            start="/d/qujing/wuzhuang/chengyun";
            message("vision", HIR+"突然火光一闪,"+me->name()+"从中冒了出来。\n"NOR,
              environment(me), me);
            tell_object(me, HIR"你的身影突然出现在一团火焰中。\n"NOR);
            break ;
        case 3:
            start="/d/penglai/penglai";
            message("vision", HIG+"只见一段枯木裂开,"+me->name()+"从中钻了出来。\n"NOR,
              environment(me), me);
            tell_object(me, HIG"你的身影突然出现在一段枯木中。\n"NOR);
            break ;
        case 4:
            start="/d/xueshan/binggu";
            message("vision", BLU+"一股浓雾飘来，凝结成"+me->name()+"的身形。\n"NOR,
              environment(me), me);
            tell_object(me, BLU"你的身影突然出现在一团浓雾中。\n"NOR);
            break ;
        }
        me->move(start);

        return 2+random(3);

        }

        if((int)me->query_skill("taiyi",1) < 60)
                return notify_fail("你太乙仙法还不够熟练，无法使用五行法术来战斗。。。\n");

        if((int)me->query_skill("baguazhen",1) < 60)
                return notify_fail("你对五行八卦的了解还不透彻，就想用这个来打人？\n"); 

        if((int)me->query("mana") < 200 )
                return notify_fail("你的法力不够！\n");
    
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神没有办法有效集中！\n");

        me->add("mana", -200);
        me->receive_damage("sen", 20);

        if( random(me->query_skill("spells")) < 40 ) {
                write("你失败了。\n");
                return 1;
        }

        if  (target->is_busy() ) 
        { 
                msgnum = random(4);}
                else  msgnum = random(5) ;
                switch ( msgnum ) {
                case 4:    
                        msg = WHT "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见一团黑气罩在$n身上！\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break ;
                case 1:
                        msg = HIY "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见一道金光射向$n！\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 800 ) * (int)me->query("kee");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 2:
                        msg = HIR "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见一团火焰直逼$n！\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 1600 ) * (int)me->query("sen");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");

                        break;
                case 3:
                        msg = HIG "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只见空中落下无数巨木，向$n当头砸下！\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 1200 ) * (int)me->query("max_force");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 0:
                        msg = BLU "$N口中喃喃地念著咒文，忽然大喝一声“疾！”\n"  +
                        "只听一声海啸，一股巨浪正向$n冲来！\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 2400 ) * (int)me->query("max_mana");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                }
                if( random(ap + dp) > dp )  {

                        switch (msgnum) {
                        case 4:

                                busy_time  += (int)me->query("mana_factor")/50;
                                if ( busy_time < 0 ) busy_time = 0 ;
                                if (busy_time > 7) busy_time =8;            
                                target->start_busy(busy_time+2);
                                msg +=  WHT "\n$n被黑气笼罩，只觉得四周灰蒙蒙地一片，什么也看不清楚！\n" NOR;
                                break;
                        case 1:
                                damage = (int)me->query("max_mana") / 10
                                + random((int)me->query("eff_kee") / 3);
                                damage -= (int)target->query("max_mana") / 15
                                + random((int)target->query("eff_kee") / 4);
                                damage += (int)me->query("mana_factor")
                                - (int)target->query("mana_factor");
                                if (damage > 0) msg +=  HIY "\n结果「嗤」地一声，金光从$n身上透体而过，
                 \n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
                                if (damage <= 0 ) 
                                {
                                        msg += HIY "\n但是$n运气硬挡了这一下，并无大碍 。\n" NOR;
                                        damage =10;
                                }
                                if (damage > 0) damage +=random((damage*(int)me->query_skill("spells"))/100);
                                if (damage > 0) target->receive_damage("kee", damage, me);
                                if (damage > 0) target->receive_wound("kee", damage/4, me);
                                break;
                        case 2:
                                damage = (int)me->query("max_mana") / 10 +
                                random((int)me->query("eff_sen") / 5);
                                damage -= (int)target->query("max_mana") / 15 +
                                random((int)target->query("eff_sen") / 8);
                                damage+=(int)me->query("mana_factor")-(int)target->query("mana_factor");
                                if( damage > 0 ) msg +=  HIR "\n$n被火光一逼，只觉得眼花撩乱，心神不定，差点晕倒在地！\n" NOR;
                                if ( damage <=0 ) 
                                {
                                        msg += HIR "\n$n强敛心神，居然没受太大的影响。\n" NOR; 
                                        damage = 20;
                                 }
                                damage +=random((damage*(int)me->query_skill("spells"))/100);
                                target->receive_damage("sen", damage, me);
                                target->receive_wound("sen", damage/3, me);
                
                                break;
                        case 3:
                                damage = (int)me->query("max_mana") / 20 +
                                random((int)me->query("max_force") / 10);
                                damage -= (int)target->query("max_mana") / 30 +
                                random((int)target->query("eff_force") / 15);   
                                damage +=(int)me->query("force_factor")-(int)target->query("force_factor");
                                if( damage > 0 ) msg +=  HIG "\n$n被巨木砸个正着，似乎受了些内伤！\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += HIG "\n$n见势不妙，左躲右闪，似乎只受了点擦伤。\n" NOR; 
                                        damage =5;
                                }
                                damage +=random((damage*(int)me->query_skill("spells"))/100);
                                if (( damage > 0 ) && (damage >=(int)target->query("force"))) target->set("force", 0); 
                                if ((damage >0) && (damage < (int)target->query("force"))) target->add("force", -damage);
        
                                break;  
                        case 0:
                                damage = (int)me->query("max_mana") / 10 +
                                random((int)me->query("max_mana") / 10);
                                damage -= (int)target->query("max_mana") / 15 +
                                random((int)target->query("max_mana") / 15);
                                damage+=(int)me->query("mana_factor")-(int)target->query("mana_factor");
                                if( damage > 0 ) msg +=  BLU "\n$n被巨浪淋得象落汤鸡，法力也消失了不少！\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += BLU "\n$n觉得有点空荡荡的，似乎法力受了点影响。\n" NOR; 
                                        damage = 10 ;
                                }
                                if( damage > 0 ) damage +=random((damage*(int)me->query_skill("spells"))/100);
                                if (( damage > 0 ) && (damage >=(int)target->query("mana"))) target-> set("mana", 0);
                                if (( damage > 0 ) && (damage < (int)target->query("mana"))) target-> add("mana", -damage);

                                break;
                        }
                } else {
                msg += "但是$n纵身一跃，躲开了这一击。\n";
        
        }
        message_vision(msg, me, target);
        if( ( damage > 0 ) && ( msgnum == 1 ))COMBAT_D->report_status(target);
        if( ( damage > 0 ) && ( msgnum == 2 ))COMBAT_D->report_sen_status(target);

        return 3+random(3);
}

