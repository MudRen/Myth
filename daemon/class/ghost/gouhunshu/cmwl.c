//魑魅魍魉
//cast cmwl ,hell gouhunshu
// modify by shao 2001.12.28
//四次攻击，加最后攻击
//和dx,skills有关

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, dx1,dx2,skills1,skills2,spi,mana1,mana2;

        if (!PFM_D->valid_family(me, "阎罗地府"))
                return notify_fail("非鬼族不能召唤魑魅魍魉。\n");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要想干什么？\n");

        dx1=(int)me->query("daoxing",1);
        dx2=(int)target->query("daoxing",1);
        skills1=(int)me->query_skill("spells",1);
        skills1=skills1*skills1*skills1/10;
        skills2=(target)->query_skill("spells",1);
        skills2=skills2*skills2*skills2/10;
        spi=(int)me->query_spi();
        mana1=(int)me->query("mana",1)+(int)me->query("max_mana",1);
        mana2=target->query("mana",1)+target->query("max_mana",1);
         
        if((int)me->query("mana") < 300+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 400 )
                return notify_fail("你的精神太差无法施展法术！\n");

        if((int)me->query_skill("gouhunshu",1) < 100)
                return notify_fail("就你的水平还招冥府四圣？ \n"); 

        me->add("mana", -200-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 100 ) {
                write("今天四圣陪老婆逛街去了，不在家！\n");
                return 1;
        }

        msg = HIC
"$N口中念念有词，随后大叫一声：“冥府四圣----魑魅魍魉何在？\n
只见一道黑光闪过，一个相貌一般的大头鬼----魑鬼向$n撞去！\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/4 ) {
                target->receive_damage("kee", 200, me, "cast");
                target->receive_wound("kee", 100, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//第一次攻击

        msg = HIC
"接着一个相貌丑恶的大嘴鬼----魅鬼向$n咬去！\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/4 ) {
                target->receive_damage("kee", 200, me, "cast");
                target->receive_wound("kee", 100, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//第二次攻击

        msg = HIC
"随后一个相貌平平的大手鬼----魍鬼向$n抓去！\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/3 ) {
                target->receive_damage("kee", 300, me, "cast");
                target->receive_wound("kee", 200, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//第三次攻击

        msg = HIC
"最后一个相貌英俊的大脚鬼----魉鬼向$n踹去！\n" NOR;

        message_vision(msg, me, target);

        if( random(dx1+skills1) > (dx2+skills2)/3 ) {
                target->receive_damage("kee", 300, me, "cast");
                target->receive_wound("kee", 200, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//第四次攻击

       if (random(dx1+skills1) > (dx2+skills2)*2/3 ) {
                msg = HIB
"$n刚刚一松懈，只见四鬼合一，闷嚎了一声，名曰「万鬼齐嚎」，$n只觉得
双腿无力，眼前发黑！ \n" NOR;
                message_vision(msg, me, target);
                damage=mana1-mana2+spi*20;
                if (damage < 400 )
                damage = 400;
                me->add("mana",-200);
                target->start_busy(4);
                target->receive_damage("kee", damage, me, "cast");
                target->receive_wound("kee", damage, me, "cast");
                COMBAT_D->report_status(target,0);
                                                    }

//第五次

        if( !target->is_fighting(me) )  
        { 
                if( living(target) )  
                { 
                        if( userp(target) ) target->fight_ob(me); 
                        else me->kill_ob(target); 
                } 
        } 

//       me->start_busy(2);
       return 3+random(2);

}


