// exercise.c
// modify by mudring Jan/03/2003

#include <skill.h>

int exercising(object me);
int halt_exercise(object me);

int main(object me, string arg)
{
    string force;
    mapping msg;
    int exercise_cost, max;
    object where;

    seteuid(getuid());

    where = environment(me);
        
    if (!arg || !sscanf(arg, "%d", exercise_cost))
        return notify_fail("你要花多少气练功？\n");

    if (exercise_cost <= 0 && me->query_temp("pending/exercise"))
    {
        return halt_exercise(me);
    }

    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");

    if (me->is_fighting())
        return notify_fail("战斗中不能练内功，会走火入魔。\n");

    if (where->query("no_fight"))
        return notify_fail("安全区内禁止练功。\n");

    if (me->query_condition("no_force"))
         return notify_fail("你感到体内气息乱窜，无法聚气打坐！\n");
                
    if (!(force = me->query_skill_mapped("force")))
        return notify_fail("你必须先用 enable 选择你要用的特殊内功。\n");

    if (me->query("food") < 40 || me->query("water") < 40)
        return notify_fail("你太饥饿了，实在无气力使用内力。\n");

    if (exercise_cost < 20)
        return notify_fail("你最少要花 20 点「气」才能练功。\n");

    if ((int)me->query("kee") < exercise_cost)
        return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

    msg = SKILL_D(force)->exercise_msg(me);
    if (!msg || undefinedp(msg["start_my_msg"]))
        write("你坐下来运气用功，一股内息开始在体内流动。\n");
    else
        write(msg["start_my_msg"]);

    me->set_temp("pending/exercise", 1);
    me->set_temp("exercise_cost", exercise_cost);

/*
    if (!msg || undefinedp(msg["start_other_msg"]))
        tell_room(environment(me),
                  me->name() + "盘膝坐下，开始运功打坐。\n", ({ me }));
    else
        tell_room(environment(me),
                  msg["start_other_msg"], ({ me }));
*/

    me->start_busy((: exercising :), (:halt_exercise:));
    return 1;
}

int exercising(object me)
{
    string force;
    mapping msg;

    int exercise_cost = (int)me->query_temp("exercise_cost");
    int force_gain = (int)me->query_skill("force",1)/10
               +(int)me->query_con()/3 + random(3);

    int max = me->query_max_force();

//    if (force_gain > exercise_cost) force_gain = exercise_cost;
    if (force_gain < 5) force_gain = 20;
    if (force_gain > 25) force_gain = 100;
    force_gain = 100;
    force_gain*=2;

    me->receive_damage("kee", 20);
    me->add("force", force_gain);
    me->set_temp("exercise_cost", exercise_cost -= 20);

    if (me->query("force") > me->query("max_force") * 2)
    {
        if (me->query("max_force") >= max)
        {
            tell_object(me, "当你的内息遍布全身经脉时却没有功力提升的迹象，"
                        "似乎内力修为已经遇到了瓶颈。\n");
        } else
        {
            me->set("force", me->add("max_force", 1));
            tell_object(me, "你的内力增强了！\n");
 
            if (me->query("max_force") > me->query("maximum_force"))
                me->set("maximum_force", me->query("max_force"));
        }
        me->set("force", me->query("max_force"));
        return halt_exercise(me);
    }

    force = me->query_skill_mapped("force");
    if (force) msg = SKILL_D(force)->exercise_msg(me);
    if (exercise_cost > 0)
    {
        if (msg && !undefinedp(msg["exec_my_msg"]))
            tell_object(me, msg["exec_my_msg"]);
        if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
            tell_room(environment(me), msg["exec_other_msg"], ({me}));
        return 1;
    }

    me->delete_temp("pending/exercise");
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "你行功完毕，吸一口气，缓缓站了起来。\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"行功完毕，吸一口气，缓缓站了起来。\n", ({me}));
    else
        tell_room(environment(me),
                  msg["end_other_msg"], ({me}));
*/
    me->start_busy(1);
    return 0;
}

int halt_exercise(object me)
{
    string force;
    mapping msg;

    if (me->query("force") > me->query("max_force") * 2)
        me->set("force", me->query("max_force") * 2);
    me->delete_temp("pending/exercise");
    force = me->query_skill_mapped("force");
    if (force) msg = SKILL_D(force)->exercise_msg(me);
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "你行功完毕，吸一口气，缓缓站了起来。\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"行功完毕，吸一口气，缓缓站了起来。\n", ({me}));
    else
        tell_room(environment(me),
                  msg["end_other_msg"], ({me}));
*/
    me->start_busy(1);
    return 1;
}

void remove()
{
    object *obs = users();
    foreach (object ob in obs)
    {
        if (ob->query_temp("pending"))
        {
            ob->start_busy(1, 2);
            ob->interrupt_me();
            ob->start_busy(1);
        }
    }
}


int help(object me)
{
        write(@HELP
指令格式 : exercise|dazuo [<耗费「气」的量>]
           exercise|dazuo 0 ：停止打坐

运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。

请参考 help stats
HELP
        );
        return 1;
}

