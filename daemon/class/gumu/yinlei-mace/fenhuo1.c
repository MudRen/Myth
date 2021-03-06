//天雷焚火
//by junhyun@SK
//要求 使用者 气血 精神 小于50%

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你相对谁使用【天雷焚火】？\n");
        
      if((int)me->query_skill("yinlei-mace", 1) <120)
            return notify_fail("你的银雷鞭法火候还不够！\n");
      if (me->query_skill_mapped("force")!="jiuyin-force")
                return notify_fail("天雷焚火要用九阴真经做底子。\n");
     if (me->query_skill("jiuyin-force",1)<120) 
         return notify_fail("你的九阴真经不够纯熟。\n");
      if (!target->is_fighting(me))
             return notify_fail("你们在战斗么？\n");
      if (!target->is_killing(me->query("id")))
             return notify_fail("比武要讲武德！\n");
       eff_qi=me->query("eff_kee");
       max_qi=me->query("max_kee");
       qi_pcg=eff_qi*100/max_qi;
//       if (qi_pcg>=50) 
//           return notify_fail("时机未到，静观其变。\n");
       if (me->query("force")<200)
           return notify_fail("你内力不继，心有余而力不足。\n");

//        me->set("kee", 1);  //没有必要了，eff决定就行了。
        me->set("eff_kee",eff_qi*random(10)/100);
      if ( me->query("eff_kee") <1 ) me->set("eff_kee",1); 
//        me->set("sen",1);
        me->set("eff_sen",me->query("eff_sen")*random(10)/100);
      if ( me->query("eff_sen") <1 ) me->set("eff_sen",1); 
        me->set("force",1);
        me->set("mana",1);/* 以上所有的数值不能为0，否则会莫名其妙的死了的。cigar */

        msg = HIR"\n只听一声爆喝，$N伸手向天一指，招来滚滚天雷，纵身跳入雷电之中
用自己一身内力催动着雷电使出一招焚天化地的————

                     ┏━┓
                     ┃天┃
                     ┗━┛
                       ┃
                     ┏━┓
                     ┃雷┃
                     ┗━┛
                       ┃
                     ┏━┓
                     ┃焚┃
                     ┗━┛
                       ┃
                     ┏━┓
                     ┃火┃
                     ┗━┛
"
                 +"雷电化做一道烈火，般扑向$n！\n" NOR;
        ap = me->query_skill("yinlei-mace", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;
        if( random(ap + dp) <  dp ) {
              msg += HIB "$n一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR;
              message_vision(msg, me, target);
         } else {
//                  target->set("kee",-1)
                  target->receive_damage("kee",target->query("kee")*2,me);
                  msg += HIR "$n不料$N有如此一招，为此气势所慑，竟然楞在当地，忘了招架。\n
说时迟，那时快，这道白光已在$n身上当胸穿过！\n"NOR;
                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(2+random(3));
          target->start_busy(random(3));
          return 1;
}

