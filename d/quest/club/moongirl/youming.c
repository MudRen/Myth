//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "��ڤ��");
        set ("long", @LONG

������õĿռ䣬һ�ֿն��ĸо��������ֻص�ʥ����
�����ε���

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "east" : __DIR__"gong5",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/strange" : 1,
        ]));

        set("indoors", "��ڤ��");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

