//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "��˿��");
        set ("long", @LONG

����ĵ�о��������ȥ���ģ������쳾����ʲô������
��ƺ���̣�������ƽ����������ְɡ�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : __DIR__"gong4",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/cygracal" : 1,
        ]));

        set("indoors", "��˿��");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

