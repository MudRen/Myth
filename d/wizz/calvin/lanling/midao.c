//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�ܵ�");
        set ("long", @LONG

����һƬ��� ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/calvin/lanling/liou.c",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//         set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
