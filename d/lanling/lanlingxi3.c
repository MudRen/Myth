//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "��������");
        set ("long", @LONG

����������������ǵ�����,����һ·�Ͼ�������,�ò�����!

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "westdown" : "/d/changan/eastseashore",
                "east" : "/d/calvin/lanling/lanlingxi2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
