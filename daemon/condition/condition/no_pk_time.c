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
        tell_object(me, "��ͥ����ͨ�����ˣ�\n");
        message_system("̫�׽��ǣ�" + "��Ϊ" + me->name(1) + "(" +
                       getuid(me) + ")һֱû�ܱ����ù鰸����ͥ�Ѿ�ȡ����ͨ����");
        return 0;
    }

    if (env)
    {
/*
        if (me->query_condition("no_pk_time") > 480 &&
            (file_name(env) != JAIL_ROOM))
        {
            me->apply_condition("in_jail", 360 * 2);
            me->move(JAIL_ROOM);
            me->set("startroom", JAIL_ROOM);
            tell_object(me,"�ٺ٣�ɱ�����飬��ץ�˰ɣ�������\n");
            message_system("̫�׽��ǣ�" + me->name(1) + "(" + getuid(me) +
                           ")ɱ�����飬�����һң��վ�����ͥ�������Ρ�");
        }
*/

        if ((userp(env) || env->query("no_pk")) &&
            !me->is_ghost())
        {
            me->receive_wound("sen", damage_sen);
            me->receive_wound("kee", damage_kee);
            message_vision("���ϳ���һ�����磬��������������������$N��ͷ�ϡ�\n", me);
            me->set_temp("death_msg","�����������ˡ�");
            me->apply_condition("no_pk_time", duration);
        }
    }

    me->apply_condition("no_pk_time", duration-1);
    return CND_CONTINUE;
}

