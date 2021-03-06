//clublevel.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string id, type, res;
    object ob;
    int level_me, level_ob, level;

    if (!me->query("club_master") && !wizardp(me))
        return notify_fail("只有帮会领导人才可以设置帮会成员的等级？\n");

    if (!arg)
        return notify_fail("指令格式：clublevel <某人> <级别(0-10)>\n");

    if (sscanf(arg, "%s %s", id, level) == 2)
        ob = present(id, environment(me));
    else 
        return notify_fail("指令格式：clublevel <某人> <级别(0-10)>\n");

    if (!ob)
        return notify_fail("这里没有这个人。\n");

    if (ob == me && !wizardp(me))
        return notify_fail("你不能修改自己的帮派等级。\n");

    if (!userp(ob) && !wizardp(me))
        return notify_fail("看清楚，那并不是人！\n");

    if (ob->query("club") != me->query("club") && !wizardp(me))
        return notify_fail("你只对本帮会的玩家使用这条命令！\n");

    if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着呢！\n");

    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("对方正忙着呢！\n");

    if (level > 10 || level < 0)
        return notify_fail("你只能设置0－10的级别！\n");

    if (level = 10)
        return notify_fail("你难道想让"+ob->query("name")+"代替你帮主的位置？！\n");
    
    level_me = me->query("club_level");
    level_ob = ob->query("club_level");

    if( level > level_ob )
        {
            type="提升";
            res ="并和$n握手勉励一番";
        }
    else
        {
            type = "降";
             res ="并拍拍$n的肩膀期勉$n能将功折罪";
        }

    message_vision("$N将$n的帮派职位等级"+type+"为"+chinese_number(level)+"级，"+res+"。\n",me,ob);

    ob->set("club_level", level);

    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : clublevel <某人> <级别(0-10)>

设置帮会成员的职位等级。
HELP
    );
    return 1;
}


