//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "�������¸�");
        set ("long", @LONG

�Ĵ�Ʈɢ�ŵ���������������¹�͸���촰����˪ѩ��
���ڵذ��ϡ�������¡������������������ˡ�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
      "north" : __DIR__"gong4", 
       "south" : __DIR__"gong3",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/qiao" : 1,
        ]));

        set("indoors", "�������¸�");
        set("no_clean_up", 0);
        set("no_fight", 1); 
        set("no_magic", 1); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

