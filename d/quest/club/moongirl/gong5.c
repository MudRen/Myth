//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "����ͨ��");
        set ("long", @LONG

���������¹��ĺ�,������������Ļ�����ľ��ɽʯ������
Ϫˮ���������ﻨ�㣬��һ���˼��ɾ�


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"moon5", 
       "south" : __DIR__"moon4",  
       "west" : __DIR__"youming",  
       "east" : __DIR__"meishi", 
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("outdoors", "����ͨ��");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

