//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����");
        set ("long", @LONG

�����ǰ�������ס�ĵط������䲼�õĻ�����ͦ���ӵġ�����
���߷���һ�Ŵ����ϱ߿��˴����������ڴ��£�ɹɹ���⻹ͦ��
���ġ�
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "east" : __DIR__"wuwai",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("no_clean_up", 0);
        set("no_fight", 1);
        set("light_up", 1);
        set("no_magic", 1);
        set("sleep_room", 1);

        setup();
        replace_program(ROOM);
}

