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
            tell_object(me, "��ͥ���⣬���㷵���˼�������У��мǲ�������ɱ����\n");
            message_system("̫�׽��ǣ�" + me->name(1) + "(" + getuid(me) +
                           ")���Ļڸģ���ʱ�ŷ��˼����л��ơ�");
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
            tell_object(me,"�ٺ٣������ܣ��ֱ�ץ�˰ɣ�������\n");
            message_system("̫�׽��ǣ�" + me->name(1) + "(" + getuid(me) +
                           ")��ͼ���������ѣ����ڼӳ���");
            return 1;
        }   
    }

    me->apply_condition("in_jail", duration - 1);
    return CND_CONTINUE;
}

