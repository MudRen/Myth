//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "���Ƹ�");
        set ("long", @LONG

���ٳ߽�â�ٴ����ֽ������Ƿ�����һ��Ѫ�ȵ�ɱ¾������
�ɴ����ٴ��ſ������ж����޹�������ɥ����ЪϢһ�°�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : __DIR__"gong3",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/loveuu" : 1,
        ]));

        set("indoors", "���Ƹ�");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

