//clubdemise.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(string arg)
{
    string club_name;
    object ob ,me;
    me=this_player();

    if (!me->query("club_master"))
        return notify_fail("只有帮会领导人才可以用传位的命令。\n");

    if (!arg)
        return notify_fail("你要将帮派大权移交给谁？\n");

    if (sscanf(arg, "%s", arg) == 1)
        ob = present(arg, environment(me));
    else 
        return notify_fail("指令格式：clubdemise <某人> \n");

    if (!ob)
        return notify_fail("这里没有这个人。\n");

    if (ob == me)
        return notify_fail("你想继续当帮主何必传位呢？\n");

    if (!userp(ob) && !wizardp(me))
        return notify_fail("这里有这个人吗？\n");

    if (ob->query("club") != me->query("club") && !wizardp(me))
        return notify_fail("你只对本帮会的玩家使用这条命令！\n");

    if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着呢！\n");

    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("对方正忙着呢！\n");
    
    club_name=me->query("club");
    me->delete("club_master");
    me->set("club_level", 9);
    ob->set("club_level", 10);
    ob->set("club_master", 1);

    message_vision("$N将"+club_name+"的总指挥权移交给$n。\n",me,ob);
    message( "channel:club",CYN+"【"+club_name+"】"+me->query("name")+"("+capitalize(me->query("id"))+")将"+club_name+"指挥权移交给"+ob->query("name")+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );

    ob->save();
    me->save();
    return 1;
}


int help(object me)
{
write(@HELP
指令格式 : clubdemise <某人> 

帮会的头领将帮会大权移交另外一个人。
HELP
    );
    return 1;
}


