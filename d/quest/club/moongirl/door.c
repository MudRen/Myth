//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

������Ǿ������¹��Ĺ��ţ����Ⱥ�������ϱ������Ƕ��
һ����˿��Ŷ�����ϸȥ����Ȼ��һ����˿�ȭͷ�������
���Ƴɣ��ŵ������ûƽ�����ţ�������һ�����Ҷ��߹��
�о���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"gong1",
//       "south" : "/d/club/clubbar",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

