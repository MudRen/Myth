// halt.c

#define SCHEME_CMD      "/cmds/usr/scheme"

int main(object me, string arg)
{
        object ob;

        if( arg && wizardp(me) ) {
                ob = present(arg, environment(me));
                if( !ob ) return notify_fail("没有这个生物。\n");
                if( !ob->is_fighting() ) return notify_fail(ob->name()+"现在不忙。\n");
                ob->remove_all_enemy();
                message_vision("\n$N用巫师的神力停止了$n的战斗。\n", me, ob);
                return 1;
        }

        if (me->query("doing") == "scheme")
        {
                // 执行计划中，终止
                write("你决定中止计划。\n");
                SCHEME_CMD->cancel_schedule(me);
                if (! me->is_busy())
                        return 1;
        }

        if (me->is_busy() && ! intp(me->query_busy()))
        {
                me->interrupt_me(me);
                return 1;
        } else
        if (me->is_fighting())
        {
                me->remove_all_enemy(0);
                message_vision("$N身行向后一跃，跳出战圈不打了。\n", me); 
                if (objectp(ob = me->query_competitor()) &&
                    ! ob->is_fighting(me))
                {
                        ob->win();
                        me->lost();
                }
                return 1;
        }
        else
        if (me->is_busy())
                return notify_fail("你现在停不下来。\n");
        else
                return notify_fail("你现在不忙。\n");

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : halt

中止你目前正在做的事情，比如打坐、吐纳或者是某些工作。如果
你和别人正在动手，则这条命令会让你停手，当然前提是对方并不
想杀死你，否则使用这条命令没有效果。

如果你正在和人比武或是接受挑战而且并不是见生死方式，则该命
令即作为认输处理。

其他相关指令: accept, fight, hit, scheme

HELP );
        return 1;
}

