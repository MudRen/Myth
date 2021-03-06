// in_jail.c
// by mudring Sep/19/2002

#include <ansi.h>
#include <condition.h>

#define JAIL_ROOM  "/d/wiz/jail"
#define OUT_ROOM   "/d/city/kezhan"

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

    object env=environment(me);

    if (duration < 1)
    {
        if (file_name(env) == JAIL_ROOM) 
        {
            tell_object(me, "天庭特赦，放你返还人间继续修行，切记不可再乱杀生！\n");
            message_system("太白金星：" + me->name(1) + "(" + getuid(me) +
                           ")诚心悔改，暂时放返人间修行积善。");
            me->move(OUT_ROOM);
            me->set("startroom", OUT_ROOM);
			EXAMINE_D->examine_player(me);
            me->save();
            return 0;
        }
    }

    if (env)
    {
        if (me->query_condition("in_jail") &&
            (file_name(env) != JAIL_ROOM))
        {
            me->apply_condition("in_jail",180 + me->query_condition("in_jail"));
            me->move(JAIL_ROOM);
            me->set("startroom", JAIL_ROOM);
            me->save();
            tell_object(me,"嘿嘿，想逃跑，又被抓了吧！！？？\n");
            message_system("太白金星：" + me->name(1) + "(" + getuid(me) +
                           ")试图从天牢逃脱，刑期加长。");
            return 1;
        }   
    }

    me->apply_condition("in_jail", duration - 1);
    return CND_CONTINUE;
}

