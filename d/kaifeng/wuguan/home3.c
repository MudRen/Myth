inherit ROOM;
#include <ansi.h>
#include "leave.h"
void create ()
{
        set ("short",HIB "�����"NOR);
        set ("long",HIB @LONG


                            �����           


          ���飬����Ƹ�ĺ���У���������ź���֪������ 


LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home4",
                "south" : "/d/kaifeng/wuguan/home2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}
