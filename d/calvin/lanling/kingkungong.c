//shulin ����

inherit ROOM;

void create ()

{
        set ("short", "����");
        set ("long", @LONG

���������깬��һ�󹬵�,����������������ص�����
��ΰ����׳�۵�Ǭ���Ƕ�������ٹ���ϢСȤ�ĵط�
����װ�޵���,������Ŀ ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/d/calvin/lanling/kingqiangong",
                "south" : "/d/calvin/lanling/kingziminggong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//        set("outdoors", "changan")
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
