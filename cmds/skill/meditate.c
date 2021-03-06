// meditate.c
// modify by mudring Jan/03/2003

#include <skill.h>

int meditating(object me);
int halt_meditate(object me);
int main(object me, string arg)
{
    string mana;
    mapping msg;
    int meditate_cost, max;
    object where;

    seteuid(getuid());

    where = environment(me);
        
    if (!arg || !sscanf(arg, "%d", meditate_cost))
        return notify_fail("你要花多少精神冥思？\n");

    if (meditate_cost <= 0 && me->query_temp("pending/meditate"))
    {
        return halt_meditate(me);
    }

    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");

    if (me->is_fighting())
        return notify_fail("战斗中不能冥思，会走火入魔。\n");

    if (where->query("no_fight"))
        return notify_fail("这里不是修炼法力的地方。\n");

    if (me->query_condition("no_mana"))
         return notify_fail("你感到体神智迷糊，无法冥思！\n");
              
    if (!(mana = me->query_skill_mapped("spells")))
        return notify_fail("你必须先用 enable 选择你要用的法术。\n");

    if (me->query("food") < 40 || me->query("water") < 40)
        return notify_fail("你太饥饿了，实在无气力使用内力。\n");

    if (meditate_cost < 20)
        return notify_fail("你最少要花 20 点「精神」才能冥思。\n");

    if ((int)me->query("sen") < meditate_cost)
        return notify_fail("你现在神智不清,不能再想入非非了。\n");

    msg = SKILL_D(mana)->meditate_msg(me);
    if (!msg || undefinedp(msg["start_my_msg"]))
        write("你盘膝而坐，静坐冥思了一会儿。\n");
    else
        write(msg["start_my_msg"]);

    me->set_temp("pending/meditate", 1);
    me->set_temp("meditate_cost", meditate_cost);

/*
    if (!msg || undefinedp(msg["start_other_msg"]))
        tell_room(environment(me),
                  me->name() + "盘膝而坐，静坐冥思了一会儿。\n", ({ me }));
    else
        tell_room(environment(me),
                  msg["start_other_msg"], ({ me }));
*/

    me->start_busy((: meditating :), (:halt_meditate:));
    return 1;
}

int meditating(object me)
{
    string mana;
    mapping msg;

    int meditate_cost = (int)me->query_temp("meditate_cost");
    int mana_gain     = (int)me->query_skill("spells",1) / 10
                        + (int)me->query_spi() / 3 + random(3);

    int max = me->query_max_mana();

//    if (mana_gain > meditate_cost) mana_gain = meditate_cost;
    if (mana_gain < 5) mana_gain = 20;
    if (mana_gain > 25) mana_gain = 100;
    mana_gain = 100;
    mana_gain*=2;

    me->receive_damage("sen", 20);
    me->add("mana", mana_gain);
    me->set_temp("meditate_cost", meditate_cost -= 20);

    if (me->query("mana") > me->query("max_mana") * 2)
    {
        if (me->query("max_mana") >= max)
        {
            tell_object(me, "当你的法力增加的瞬间你忽然觉得脑中一片混乱，"
                        "似乎法力的提升已经到了瓶颈。\n");
        } else
        {
            me->set("mana", me->add("max_mana", 1));
            tell_object(me, "你的法力增强了！\n");
 
            if (me->query("max_mana") > me->query("maximum_mana"))
                me->set("maximum_mana", me->query("max_mana"));
        }
        me->set("mana", me->query("max_mana"));
        return halt_meditate(me);
    }

    mana = me->query_skill_mapped("spells");
    if (mana) msg = SKILL_D(mana)->meditate_msg(me);
    if (meditate_cost > 0)
    {
        if (msg && !undefinedp(msg["exec_my_msg"]))
            tell_object(me, msg["exec_my_msg"]);
        if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
            tell_room(environment(me), msg["exec_other_msg"], ({me}));
        return 1;
    }

    me->delete_temp("pending/meditate");
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "你行功完毕，从冥思中回过神来。\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"行功完毕，从冥思中回过神来。\n", ({me}));
    else
        tell_room(environment(me),
                  msg["end_other_msg"], ({me}));
*/
    me->start_busy(1);
    return 0;
}

int halt_meditate(object me)
{
    string mana;
    mapping msg;

    if (me->query("mana") > me->query("max_mana") * 2)
        me->set("mana", me->query("max_mana") * 2);
    me->delete_temp("pending/meditate");
    mana = me->query_skill_mapped("spells");
    if (mana) msg = SKILL_D(mana)->meditate_msg(me);
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "你行功完毕，从冥思中回过神来。\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"行功完毕，从冥思中回过神来。\n", ({me}));
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
指令格式 : meditate|mingsi [<耗费「神」的量，预设值 30>]
           meditate|mingsi 0 ：停止冥思
 
静坐冥思，将游离的精神力有效地集中凝聚成能够用来施展法术的能量
，藉以增加自己的法力。

HELP
        );
        return 1;
}
