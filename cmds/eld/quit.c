// quit.c
// Modify by mudring@SanJie

#include <command.h>
#include <config.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
        set("channel_id", "离线指令");
}

int main(object me, string arg)
{
    int i;
    object *inv, link_ob;

    if (me->query_temp("no_move"))
        return notify_fail("你被定住了，哪里退得出游戏！\n");

    if (me->is_busy() && ! me->query("doing"))
        return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");

    if (me->is_fighting())
        return notify_fail("你现在正在打架，怎么能说走就走？\n");

    if (me->query("kee") <= 0 || me->query("sen") <= 0)
        return notify_fail("你现在的身体状况不适合离开游戏！\n");

    if (me->is_pker())
        return notify_fail("你刚杀完人就想离开？做事情还是要负责任的！\n");

    if (environment(me)->query("no_quit"))
        return notify_fail("这里不准退出游戏。\n");

    if (me->run_override("quit"))
        return 1;

    link_ob = me->query_temp("link_ob");

    // We might be called on a link_dead player, so check this.
    if (objectp(link_ob))
    {
        // Are we possessing in others body ?
        if (link_ob->is_character())
        {
            write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
            exec(link_ob, me);
            link_ob->setup();
            link_ob->write_prompt();
            return 1;
        }

        if (link_ob->query_temp("last_from"))
        {
            link_ob->set("last_on", time());
            link_ob->set("last_from",
                link_ob->query_temp("last_from"));
            link_ob->set("registered",
                me->query("registered"));
            link_ob->save();
        }
        destruct(link_ob);
    }

    if (me->query("doing"))
    {
        if (! interactive(me))
            return 1;

        write("你暂时离线，人物不退出...\n");
        message("vision", me->name() + "离线了。\n",
                environment(me), ({ me }));
        me->save();
        link_ob = new(LOGIN_OB);
        exec(link_ob, me);
        destruct(link_ob);
        return 1;
    }

#if INSTALL_EXAMINE
    EXAMINE_D->examine_player(me);
#endif
    me->log_command("quit");

    if (! wizardp(me))
    {
        int flag;
        flag = 0;
        inv = all_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
            if (! inv[i]->query_autoload() && ! inv[i]->query("equipped"))
                        flag += DROP_CMD->do_drop(me, inv[i], 1);
        if (flag)
            message("vision", me->name() + "将身上的东西都丢了下来。\n",
                    environment(me), ({ me }));
    }

    if (me->query_team()) me->dismiss_team();

    write("欢迎下次再来！\n");

    if (environment(me))
    {
        message("vision", me->name() + "离开游戏。\n",
            environment(me), ({ me }));
    }

    CHANNEL_D->do_channel(this_object(), wiz_level(me)?"wiz":"sys",
            me->name(1) + "(" + me->query("id") + ")离开游戏了，停留时间为："
            + chinese_time(time()-me->query_temp("logon_time")));

    log_file("stat", sprintf("%-8s %-10s %-18s %-18s %-15s.\n",
                             me->name(1), me->query("id"),
                             ctime(me->query_temp("logon_time")),
                             ctime(time()),
                             interactive(me) ? query_ip_number(me) : "unknow"));

    me->save();
    me->end_log();
    destruct(me);

    return 1;
}

int force_quit(object me)
{
    if (previous_object() != me ||
        ! playerp(me))
        return notify_fail("你不能摧毁这个对象。\n");

    seteuid(getuid());
    CHANNEL_D->do_channel(this_object(), wiz_level(me)?"wiz":"sys",
            me->name(1) + "(" + me->query("id") + ")被系统强制离开了游戏，停留时间为："
            + chinese_time(time()-me->query_temp("logon_time")));

    me->save();
    if (environment(me) != find_object(VOID_OB))
        me->move(VOID_OB, 1);
    destruct(me);
    return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}

