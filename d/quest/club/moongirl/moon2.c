//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "���¹�");
        set ("long", @LONG

������߽���һ��ͯ�������磬����������ô�ÿɰ�������
�����ˡ���ҹ���¡������ޣ���������Ķ�����Ц�ء�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"gong3", 
       "south" : __DIR__"gong2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/buwawa" : 1,
        ]));

        set("indoors", "���¹�");
        set("no_clean_up", 0);
        set("no_fight", 1); 
        set("no_magic", 1); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

