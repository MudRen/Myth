//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

����������ǵĶ���,��������·������ľ����,����ʤ��.

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/lanling/yuhua3",
                "east" : "/d/lanling/lanlingdong2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
