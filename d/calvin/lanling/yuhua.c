//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�껨ʯ·");
        set ("long", @LONG

����������ĵ������,����������Ϻ�,��������
�ϸߵ���ҵ�,�����������������ľ���,����ʱ
���н�ͨ�������������,�������Ҳ�ǵ��عٸ���
Ϊͷʹ����

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                 "west" : "/d/calvin/lanling/center",
                "east" : "/d/calvin/lanling/xiaolu2",
                 "north" : "/d/calvin/lanling/tan1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
