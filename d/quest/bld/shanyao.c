//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ��");
        set ("long", @LONG

��Ȼֻ����ɽɽ������������Ҳ�൱���ˡ�СϪ������������С��
������質�������˸о�������Ȼ�������������̲�סͣ����������
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southdown" : __DIR__"shanlu4",
                "eastup" : __DIR__"shanlu5",
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


