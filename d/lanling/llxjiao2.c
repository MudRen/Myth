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
                "west" : "/u/calvin/����/����/��������3",
                "east" : "/u/calvin/����/����/��������1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
