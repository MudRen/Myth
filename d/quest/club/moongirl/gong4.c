//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "�껨ʯ·");
        set ("long", @LONG

���������¹���,�������������,һ�����껨ʯ�̳ɵ�·
��ֱ��ͨ�����̴̱���


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"moon4", 
       "south" : __DIR__"moon3",   
       "west" : __DIR__"taiyi",  
       "east" : __DIR__"chansi",  
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("outdoors", "�껨ʯ·");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

