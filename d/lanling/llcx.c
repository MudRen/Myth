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

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/d/calvin/lanling/jie8",
                "south" : "/d/calvin/lanling/kingdadao1",
                "west" : "/d/calvin/lanling/stone1",
                "east" : "/d/calvin/lanling/yuhua",
// 25                  "down" : "/d/calvin/lanling/feixu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//            "/u/calvin/����/board" : 1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
// 36   call_other("/obj/board/lanling_b","???");
        replace_program(ROOM);
}
