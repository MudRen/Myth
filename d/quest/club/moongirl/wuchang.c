//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG

����������¹������䳡��������ʮ�˰�����������¹�
���˶���Ů�ӣ���������˿���������˲�


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "west" : __DIR__"gong1", 
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("outdoors", "���䳡");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

