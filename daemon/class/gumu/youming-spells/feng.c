//轩辕古墓 幽明神通 幽明·媚
//By ivy 2002.4.5
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

        if( me->query("gender") =="女性" )
                return notify_fail("你太娇小了，控制不了强风\n");

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("youming-spells",1) < 60)
                return notify_fail("你的法术太弱 无法控制风神\n");


        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("请一次风神不容易，别浪费\n");  

        if(target->query_temp("no_move"))
        return notify_fail(target->query("name")+"已经被风刮的东倒西歪了\n");  

        if((int)me->query("mana") < 200 )
                return notify_fail("你的法力不够，无法召唤风神\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -200);
        me->receive_damage("sen", 10);

        msg = HIW
"$N一声大喝“风神何在！”半空中一声闷雷\n
几阵旋风夹杂在雷声中扑面而来，$n被风刮的政不开眼睛\n
$N双手一推，旋风将$n紧紧的包裹起来......\n" 
NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /12 ;
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
//      if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap2 = (int)me->query_per();
        dp2 = (int)target->query_per();
//      if( random(4*ap) < ((int)target->query_cps()+dp)) success = 0;
//here we compare per and guy's ding li.


        ap3 = (int)me->query("mana");
        dp3 = (int)target->query("mana");
        if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;

//here we compare current mana. this is important. you need recover to try again.

        if(success == 1 ){
                msg +=  HIR "$n周身被如刀刃般狂风刮的生疼，却始终无法移动半步！\n" NOR;
                target->set_temp("no_move", 1);
        
                howlong = random((me->query_skill("spells") -100))+1;
                if(howlong>60) howlong=60;
                call_out("free", howlong, target);
        }           
        else {
                msg +=  HIR "$n嘴角路出一丝冷笑道：“雕虫小技，何足挂齿”双手一挥风平浪静！\n" NOR;   
                me->start_busy(1+random(2));        
                if( living(target) ) target->kill_ob(me);
        } 

        message_vision(msg, me, target);

        return 1;
}

void free(object target)
{
        if (target)
        target->delete_temp("no_move");      
        return;
}

