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
                "northdown" : "/u/calvin/����/����/�깬����1",
                "south" : "/u/calvin/����/����/����",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
