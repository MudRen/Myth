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
                "west" : "/d/calvin/lanling/yuhua",
                "east" : __DIR__"yuhua3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
   "/d/qujing/zhuzi/npc/people" : 2,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
