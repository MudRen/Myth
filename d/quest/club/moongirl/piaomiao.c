//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "��翸�");
        set ("long", @LONG

�����ѩ���������㣬��翼��ƻ����棬���������֣��¹�
��������·��������������������

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "east" : __DIR__"gong2",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/handson" : 1,
        ]));

        set("indoors", "��翸�");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

