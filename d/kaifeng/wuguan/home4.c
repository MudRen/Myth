inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIR "����Ů����"NOR);
        set ("long",HIR @LONG


                          ����Ů����           


          ���ģ��仨��������գ�Ů��������¥������� 


LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home5",
                "south" : "/d/kaifeng/wuguan/home3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
