//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "Ǭ��");
        set ("long", @LONG

���������깬�ĵ�һ�󹬵�,����������������ص�����
��ΰ����׳�۵�Ǭ���Ƕ�������ٹ����ֹ��Ҵ��µĵط�
����װ�޵���,������Ŀ ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "northdown" : "/d/calvin/lanling/kingdoor1",
                "south" : "/d/calvin/lanling/kingkungong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//        set("outdoors", "changan")
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
