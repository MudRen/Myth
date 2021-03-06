#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void fire_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「火鸟」？\n");
        if(!me->is_fighting())
                return notify_fail("「火鸟」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");
          if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("zizhi-blade", 1) < 60)
                return notify_fail("你的紫雉刀不够熟练，使用这一招会有困难！\n");
         if(me->query_temp("no_fire"))
                        return notify_fail("此机过于费力，小心内伤！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIR"\n$N刀过头顶，积聚全身力量，一刀劈出\n\n"NOR,me,target);
message_vision(MAG"\n刀锋带着一道紫色火焰划过,犹如一只火鸟\n"NOR,me,target);

damage=(int)me->query_skill("blade")+random((int)me->query_skill("blade"));
              if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIB"\n$n周身被紫色火焰包围着......\n"NOR,me,target);
// mudring fix nkbug
target->receive_damage("sen",damage/(random(15)+15),me,"pfm");
target->receive_wound("sen",damage/(random(15)+30),me,"pfm");
             COMBAT_D->report_status(target);
//me->start_busy(2);
}
else {
             message_vision(HIG"\n$n急忙后跃，才将将躲开火焰的攻击！\n"NOR,me,target);
             }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_fire",1);
                call_out("fire_ok",2+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}

void fire_ok(object me)
{
if (!me) return;
      me->delete_temp("no_fire");
}

