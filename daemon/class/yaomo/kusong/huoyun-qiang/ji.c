//modify by wuyou@sk_sjsh 
//2003-7-28

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="祭枪";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｊｉ\n"
        +"条件：火云枪法100级"
        +"连续两击的perform，威力一般。";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int i,j,damage;
        weapon = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「祭枪」？\n");
                
        if (!PFM_D->valid_family(me, "火云洞"))
                return notify_fail("“祭枪”只有火云洞门人才可以用！\n");

        if(!me->is_fighting())
                return notify_fail("「祭枪」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不足！\n");
               
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
              
        if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("祭枪必须配合火魔心法才能使用。\n");
          


        i=(int)me->query_skill("huoyun-qiang",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("你的火云枪级别还不够，使用这一招会有困难！\n");

        message_vision(HIR"\n只见$N向"+weapon->query("name")+HIR"上吐了口鲜血,大喝一声:祭枪！\n"NOR, me, target);
        message_vision(HIR"$N突然将手中巨枪斜向上举起，然后在半空中划出一
道圆弧，随即径直斜下逼向$n！这一瞬间，$n只觉得呼吸都停止了！\n"NOR, me, target);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) 
        {
                me->start_busy(random(2));                               
                target->start_busy(1);          
               
                damage = (int)me->query_skill("huoyun-qiang", 1)+(int)me->query_skill("spear", 1 )/2;
                damage = damage/2 + random(damage);

                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm");
                message_vision(RED"只见$n被$N一枪击中，胸前裂开一道深深的伤口，血如箭般喷射而出！\n"NOR, me, target);
        } 
        else 
        {
                message_vision(HIC"可是$n急忙抽身躲开，$N这招没有得逞。\n" NOR, me, target);
                me->start_busy(1+random(2)) ;                                                 
        }

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("HYQ_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("HYQ_perform");

        me->receive_damage("sen", random(100));
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

