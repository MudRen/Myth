//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

���Ƿ羰���˵�����ų�,һƬ���ٵľ�����ֳ�
�����Ȱ������������ֿ����,����ʯ�Ҿ͵Ľֵ�
���߶���һ������������ĸ�ʽ����,�����ǵĻ�
Ц���п��Կ���,�������ҵ���Ƿ��� ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/calvin/lanling/jie7",
                "south" : "/d/calvin/lanling/center",
                "west" : "/d/calvin/lanling/xingyuejiulou",
                "east" : "/d/calvin/lanling/dangpu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

