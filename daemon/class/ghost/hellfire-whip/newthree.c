// BY wuyou@sk_xyj 2002-12-1

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
    int ap, dp, damage, mypot;
    string msg;
    object weapon;
    int k1, k2, k3;        

    if (!target)
        target = offensive_target(me);

    if (!target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
            return notify_fail("你要对谁施展"HIG"「神·人·鬼」"+NOR"三击？\n");
    
    if (!me->is_fighting())
        return notify_fail("「神·人·鬼」只能在战斗中使用！\n");
 
    if (!PFM_D->valid_family(me, "阎罗地府"))
        return notify_fail("「神·人·鬼」是冥界秘技！\n");
                
    if ((int)me->query_skill("zhuihun-sword", 1) < 200)
        return notify_fail("你的追魂剑等级不够，使用这一招会有困难！\n");

    if ((int)me->query_skill("kusang-bang", 1) < 200)
        return notify_fail("你的哭丧棒等级不够，使用这一招会有困难！\n");

    if ((int)me->query_skill("hellfire-whip", 1) < 200)
        return notify_fail("你的烈火鞭等级不够，使用这一招会有困难！\n");

    if ((int)me->query_skill("gouhunshu", 1) < 200)
        return notify_fail("你的勾魂术还不够，使用这一招会有困难！\n");

    if ((int)me->query("max_force") < 3000)
        return notify_fail("你的内力不够！\n");

    if ((int)me->query("force") < 800)
        return notify_fail("你的内力不足！\n");

    if ((int)me->query("sen") < 400)
        return notify_fail("你的精神不足，没法子施用外功！\n");

    dp = target->query("combat_exp"); 
    ap = me->query("combat_exp"); 
     
    msg = HIW"\n$N双手划一大圆，猛然托天而举，伴着天上雷鸣电闪，祭出了" BLINK + HIG"「神·人·鬼」"
        NOR HIW "三招。\n" NOR;
    msg += HIW"     \n"NOR;
    msg += HIW"        "HBRED HIG"┏━━━━┓"NOR"       "HBRED+HIG"┏━━━━┓\n"NOR;       
    msg += HIW"        "HBRED HIG"┃   "NOR BLINK HIR "弑" NOR HBRED HIG "   ┃" NOR "       "
        HBRED HIG "┃   " NOR BLINK HIR "神" NOR HBRED HIG "   ┃\n"NOR;       
    msg += HIW"        "HBRED HIG"┗━━━━┛"NOR"       "HBRED HIG"┗━━━━┛\n"NOR;       
    msg += HIM"只见$N手中长鞭在空中划了个半弧，"HIG"「烈火鞭」"HIM"直扫向$n！\n"NOR;

    k1=(int)me->query_skill("hellfire-whip", 1);      
    mypot = k1 * k1 * k1 / 10 + ap;        

    if (random(mypot + dp) > dp * 3 / 5)
    {              
        damage = k1 + random(k1) + me->query("force_factor") + 100;
        msg += HIC"结果$n被"HIG"「烈火鞭」"HIC"扫中腰部，疼痛难忍！\n"NOR;
        message_vision(msg, me, target);                                                                     

        target->receive_damage("kee",damage,me,"pfm");
        target->receive_wound("kee",damage/2,me,"pfm");
        COMBAT_D->report_status(target);                                 
    }
    else
    {
        msg +="但是被$n全躲开了。\n"NOR;
        message_vision(msg, me, target);       
    }

    msg = HIW"     \n"NOR; 
    msg += HIW"        "HBYEL+HIG"┏━━━━┓"NOR"       "HBYEL+HIG"┏━━━━┓"NOR"\n"NOR;      
    msg += HIW"        "HBYEL+HIG"┃   "NOR+BLINK+HIR"杀"NOR+HBYEL+HIG"   ┃"NOR"       "
        HBYEL+HIG"┃   "NOR BLINK HIR"人"NOR+HBYEL+HIG"   ┃"NOR"\n"NOR;
    msg += HIW"        "HBYEL+HIG"┗━━━━┛"NOR"       "HBYEL+HIG"┗━━━━┛\n"NOR;  
    msg += HIY"只见$N运用摄气决，向长鞭灌注内力，"+HIC"顿时笔直如棍，"+HIM"「哭丧棒」"
        HIY"随后而出，直砸向$n！\n"NOR;

    k2=(int)me->query_skill("kusang-bang",1);      
    mypot=k2*k2*k2/10 + ap;        
    if (random( mypot+ dp) > dp*3/5 )
    {              
        damage = k2+random(k2)+me->query("force_factor")+200;
        msg += HIC"结果$n"+HIC"被扫个正着！\n"NOR;
        message_vision(msg, me, target);                                                                      
   
        target->receive_damage("kee",damage,me,"pfm");
        target->receive_wound("kee",damage/2,me,"pfm");
        COMBAT_D->report_status(target);
    }
    else
    {
        msg +="$n巧妙的避开了。\n"NOR;
        message_vision(msg, me, target);       
    }
     
    msg = HIW"     \n"NOR; 
    msg += HIW"        "HBWHT+HIG"┏━━━━┓"NOR"       "HBWHT+HIG"┏━━━━┓"NOR"\n"NOR;      
    msg += HIW"        "HBWHT+HIG"┃   "NOR+BLINK+HIR"斩"NOR+HBWHT+HIG"   ┃"NOR"       "
        HBWHT+HIG"┃   "NOR BLINK HIR"鬼"NOR+HBWHT+HIG"   ┃"NOR"\n"NOR;
    msg += HIW"        "HBWHT+HIG"┗━━━━┛"NOR"       "HBWHT+HIG"┗━━━━┛\n"NOR;  
    msg += HIG"$N手中长鞭如剑，刺向$n的胸口，顿时百鬼齐嚎，甚是难听，原来竟是"+HIB"「追魂剑」"
        HIG"！\n"NOR;

    k3=(int)me->query_skill("zhuihun-sword",1);      
    mypot=k3*k3*k3/10 + ap;        

    if ( random( mypot+dp ) > dp*3/5 )
    {              
        damage = k3+random(k3)+me->query("force_factor")+300;
        msg += HIC"结果$n"+HIC"毫无防备，被长鞭直透胸部！\n"NOR;
        message_vision(msg, me, target);   
        target->receive_damage("kee",damage,me,"pfm");
        target->receive_wound("kee",damage/2,me,"pfm");
        me->receive_damage("kee",10);
        COMBAT_D->report_status(target);
    }
    else 
    {
        msg +="但是被$n就地一躺，躲开了。\n"NOR;
        message_vision(msg, me, target);       
    }


    me->add("force",-300);
    me->start_busy(2);

    return 1;
}


