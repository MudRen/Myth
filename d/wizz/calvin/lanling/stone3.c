//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "ʯͷ���");
        set ("long", @LONG

����������ǵĵڶ�������,��Ľ�ͨ����,·������
�����ر�Ķ�.������ȥ�����Ϻ�֮����.������ߵ���
��Ҳ�ر�Ķ�,�治��Ϊ���µ�һ�� ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/calvin/lanling/lanlingxi1",
                "east" : "/d/calvin/lanling/stone2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
