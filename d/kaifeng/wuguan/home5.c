inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIY "���ǹ�"NOR);
        set ("long",HIY @LONG


                                  ���ǰ�           


          ���ǣ��������ڽ����壬�ز�б���䣬�����˼仹�м��ȴ��縧�� 


LONG NOR);


        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/kaifeng/wuguan/home6",
                "south" : "/d/kaifeng/wuguan/home4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                "" : 1,
           ]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
