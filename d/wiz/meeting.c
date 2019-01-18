
// Room: /d/wiz/wizroom.c
// by mudring

#include <ansi.h>

inherit ROOM;

#define RINGDAY ""

void create ()
{
    set ("short", "��������");
    set ("long", @LONG
 
�������ʦ����ҽ�������ĵط�����������ʦ��ʲô�õĽ�
�������ʲô������Ҫ��ʦ����������������������޹ص���
�Խ��������棡
LONG);

    set("exits", ([ /* sizeof() == 2 */
        "down": "/d/city/kezhan",
        "north": "/d/wiz/system",
    ]));

    set("no_fight", 1);
    set("no_magic", 1);
    set("no_time", 1);

    setup();
    call_other("/obj/board/meet_b", "???");
}

void init()
{   
    add_action("say_log",({ "say","'"}));
}

int say_log(string msg)
{
    object me = this_player();
    string str = log_time();
 
    if (!msg)
        return 0;
    else
    {
        "/cmds/std/say.c"->main(me, msg);

        if (msg == "������mudring������"
            && str[0..5] == RINGDAY)
        {
            tell_object(me, "лл��\n��ҿ��֣���ҿ��֣�\n");
            if (me->query("combat_exp") > 500000
                && me->query("mudring/ring_day") < 1)
            {
                me->add("mudring/ring_day", 1);
                MONEY_D->pay_player(me, 2100000);
                MONITOR_D->mudring_log("RINGDAY", me, " got 210 gold...");
                MONITOR_D->report_debug_object_msg(me, " got 210 gold...");
            }
        }
        else
        {
            MONITOR_D->mudring_log("meeting", me, msg);
        }
    }

    return 1;
}

