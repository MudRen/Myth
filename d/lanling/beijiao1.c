//shulin ����

inherit ROOM;

void create ()

{
        set ("short", "���걱��");
        set ("long", @LONG

��������ųǵı���,·�߾�������,��������!
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/u/calvin/room/�����8",
                "south" : "/u/calvin/����/����/����2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
