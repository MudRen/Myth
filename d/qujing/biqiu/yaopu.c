inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","����ҩׯ" );
        set ("long", @LONG



��������������֡����������ء�����������



LONG);


        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "south" : __DIR__"jie3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
// 26           "/d/qujing/biqiu/npc/yaopuboss" : 1,
        "/obj/boss/biqiu_yaopu" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
