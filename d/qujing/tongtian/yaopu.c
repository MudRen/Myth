inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","����ҩ��" );
        set ("long", @LONG



��   �����աֶ֡ɡ֡��ڡ֡�����



LONG);


        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "south" : __DIR__"chen2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//        "/obj/boss/tongtian_yaopuboss.c" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
