//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "Ǭ�¹�");
        set ("long", @LONG

������Ǭ�¹�����������Χ����һƬ���ɫ�У���Ϊ����
�ǡ���פ��¡�����ѩ�Ĺ��


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"gong2", 
       "south" : __DIR__"gong1",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/dingli" : 1,
        ]));

        set("indoors", "Ǭ�¹�");
        set("no_fight", 1); 
        set("no_magic", 1); 
        setup();
        replace_program(ROOM);
}

