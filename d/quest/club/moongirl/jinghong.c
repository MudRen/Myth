//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set ("long", @LONG

һ�辪�磬������䣬�����϶�Ҳ������ˣ��������������
�е��������ҵ��������ɡ�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "west" : __DIR__"gong2",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/happly" : 1,
        ]));

        set("indoors", "�����");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

