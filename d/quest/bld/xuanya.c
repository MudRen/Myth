//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����");
        set ("long", @LONG

�����ǻ�ɽ���������¡����¿�ȥ��������ʲô���������棬��
���ԣ�jump����ȥ������
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "southdown" : __DIR__"shanbian1",
        //        "south" : __DIR__"wuwai",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{       
        if (arg!= "xuanya" && arg!= "ya" )
        return notify_fail("��Ҫ��ʲô�� \n");

this_player()->move("/d/quest/bld/wuwai");
        message_vision("ֻ��$N����һԾ���������������¡�\n",this_player());

        return 1;
}

