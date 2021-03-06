// full.c
// modify by mudring

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
    object ob;

    if (! SECURITY_D->valid_grant(me, "(immortal)"))
        return 0;

    seteuid(getuid(me));

    if (! arg) ob = me;
    else {
        ob = present(arg, environment(me));
        if (! ob) ob = find_player(arg);
        if (! ob) ob = find_living(arg);
    }

    if (! ob) return notify_fail("你要恢复谁的状态？\n");

/*
    // if pker and no wizard cant full
    if (ob->is_pker() && ! wizardp(ob))
         return notify_fail("想恢复通缉犯作弊？？\n");
*/

    // player only can full self
    if (! wizardp(me) && ob != me)
         return notify_fail("你只能恢复自己的状态！！\n");

    if (! wizardp(ob) && ob != me)
        message("channel:chat",
            HIG"【恢复精灵】某人：" + "据说" + me->name(1) +
            "恢复了"HIW + ob->name(1) + HIG" 的个人身体。\n"NOR, users());
    if (ob->is_pker() && ! wizardp(ob))
        NPC_D->full_hp_status(ob);
    else
        NPC_D->full_hp_status(ob, 1);
    if (me == ob)
        message_vision(HIY "$N" HIY "口中念念有词，不一会儿就变得"
            "精神焕发，神采奕奕。\n" NOR, me);
    else {
        message_vision(HIY "$N" HIY "伸手一指，$n" HIY "立刻精神焕"
            "发，神采奕奕。\n" NOR,
            me, ob);
    log_file("cmds/full",
        sprintf("%s full %s at %s\n",
            geteuid(me), geteuid(ob),log_time() ));
    }

    return 1;
}

int help()
{
    write(@HELP
指令格式 : full <对象名称>
 
这个指令可以恢复你(你)或指定对象(含怪物)的身体状态。
 
HELP );
    return 1;
}


