//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ·");
        set ("long", @LONG

һ���������۵�С·������ֻͨ��ɽ�ϣ�������·���ͣ���̫��
�ߡ������ǵ��Ұ��������С�ݡ�
LONG);

        set("exits", 
        ([ //sizeof() == 2
                "westdown" : __DIR__"shanyao",
                "eastup" : __DIR__"shanlu6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

