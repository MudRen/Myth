//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "̫�ҹ�");
        set ("long", @LONG

���������˵��̾��ģ��м����һ���޴��̫������ͼ��
�������̷�ң���ϣ����˸е�һ˿�徲��

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "east" : __DIR__"gong4",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/gsy" : 1,
        ]));

        set("indoors", "̫�ҹ�");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

