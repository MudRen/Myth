//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

Ѫ����ζ��ĥ������񾭣����������һ���޷����ݵĳ嶯
�����е������ڲ����Ĳ�����

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : __DIR__"gong5",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/mya" : 1,
        ]));

        set("indoors", "������");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

