inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIR "���ֹ�"NOR);
        set ("long",HIW @LONG



          �������֣�˭�����棬�������ã��˭�벢��



LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home2",
                "south" : "/d/kaifeng/east1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

