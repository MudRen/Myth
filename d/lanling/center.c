//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

����������ǵ�������,��Ľ�ͨ����,·������
�����ر�Ķ�.������ȥ���ǻʹ���,������ʯͷ
���,��˵�ߵ�ͷ�����Ϻ�֮����;�������껨ʯ
·,����·ͨ���ĵط��ܶ� ... ...

LONG);

        set("exits", 
        ([ //sizeof() == 5
        "north" : __DIR__"jie8",
        "south" : __DIR__"kingdadao1",
        "west" : __DIR__"stone1",
        "east" : __DIR__"yuhua",
        "down" : "/d/calvin/lanling/x",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
