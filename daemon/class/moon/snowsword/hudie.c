#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,add_dodge;
        string *mapped;
        mapping map;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail(HIW"你只能在战斗中使用。\n"NOR);
        if ( me->query("sen")<200 )
                return notify_fail(RED"你元神不济,强行运功会害了自己!\n"NOR);
        if ( me->query("force")<500 )
                return notify_fail(RED"你内力不够，强行运功会害了自己!\n"NOR);
        extra = me->query_skill("moondance",1); 
        if (extra < 30) return notify_fail(RED"你的冷月凝香舞还不够纯熟！\n"NOR); 
        if (me->query_skill("snowsword",1)<60) 
                return notify_fail("你的风回雪舞剑法不够成熟!\n");
        if (me->query_temp("hudie_busy")) return notify_fail("等等在跳舞吧。\n"); 

        if( me->query_skill("moondance",1)<100 && me->query_skill("snowsword",1)<100)
        {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);                
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))  
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来.\n"NOR,target);
                        target->start_busy(3);
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来.\n"+NOR,me);
                        me->start_busy(2);
                }
        }
        if( (me->query_skill("snowsword",1)<300)&&(me->query_skill("snowsword",1)>100))
        {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2)))  
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来..\n"NOR,target);
                        target->start_busy(2+random(3));
                        return 1;
                       
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来..\n"+NOR,me);
                        me->start_busy(3);
                }
        }
        if( me->query_skill("snowsword",1)>300 )   
        {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")*7/10)))                
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来...\n"NOR,target);
                        target->receive_damage("sen", extra, me, "pfm");
                        if(!userp(target)) 
                        {
                                target->add("eff_sen", -extra*2);
                                target->receive_damage("sen", extra, me, "pfm");
                        }
                                target->start_busy(4);
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来...\n"+NOR,me);
                        me->start_busy(2);
                }
        }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("hudie_busy",1);
        call_out("remove_effect",4+random(3),me);
        return 1;
}

void remove_effect(object me) 
{
        if (!me) return;
        me->delete_temp("hudie_busy");
}

