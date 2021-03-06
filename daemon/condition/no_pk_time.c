// pk_counter.c
// modify by mudring Sep/12/2002
// modify by mudring Sep/19/2002

#include <ansi.h>
#include <condition.h>

#define JAIL_ROOM  "/d/wiz/jail"
#define OUT_ROOM   "/d/city/kezhan"

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

    object env=environment(me);
    int damage_kee=300,damage_sen=300;

    if (duration < 1)
    {
        tell_object(me, "天庭不再通缉你了！\n");
        message_system("太白金星：" + "因为" + me->name(1) + "(" +
                       getuid(me) + ")一直没能被缉拿归案，天庭已经取消了通缉。");
        return 0;
    }

    if (env)
    {
// 29          if (me->query_condition("no_pk_time") > 481 &&
        if (me->query_condition("no_pk_time") > 241 &&
// 30          if (me->query_condition("no_pk_time") > 100 &&
            (file_name(env) != JAIL_ROOM) && !me->is_ghost())
        {
            me->apply_condition("in_jail", 360 * 2);
            me->move(JAIL_ROOM);
            me->set("startroom", JAIL_ROOM);
            me->save();
            tell_object(me,"嘿嘿，杀人如麻，被抓了吧！！？？\n");
            message_system("太白金星：" + me->name(1) + "(" + getuid(me) +
                           ")杀人如麻，天网灰灰，终究被天庭打入天牢。");
        }

        if ((userp(env) || env->query("no_pk")) &&
            !me->is_ghost())
        {
            me->receive_wound("sen", damage_sen);
            me->receive_wound("kee", damage_kee);
            message_vision("天上出现一道闪电，伴随着雷声，正好劈在$N的头上。\n", me);
            me->set_temp("death_msg","被天雷劈死了。");
            me->apply_condition("no_pk_time", duration);
        }
    }

    me->apply_condition("no_pk_time", duration-1);
    return CND_CONTINUE;
}

