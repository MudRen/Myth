//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "���̴̱���");
        set ("long", @LONG

������������һ˿���Ƶ��������㣬��ǰ����һ������Ͼ
�İٺϡ���������¡�С��Ĺ�����һ����ܰ�ĸо���

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"gong5", 
       "south" : __DIR__"gong4",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/xiaoyu" : 1,
        ]));

        set("indoors", "���̴̱���");
        set("no_clean_up", 0);
        set("no_fight", 1); 
        set("no_magic", 1); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

