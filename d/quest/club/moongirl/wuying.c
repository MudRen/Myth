//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "��Ӱ��");
        set ("long", @LONG

Զ����е�������������ƽ��һ����ɱ¾��ս�������˵����顣
����һ����ռ��Ѫ������ǹ��ﵡ�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "east" : __DIR__"gong3",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/hjeff" : 1,
        ]));

        set("indoors", "��Ӱ��");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

