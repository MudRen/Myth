inherit ROOM;

void create ()
{
        set ("short", "���вֿ�");
        set ("long", @LONG

�����ǼҴ���еĲֿ⣬��������϶��Ų��ٻ�����»��в��ٻ�
�񡣻����ǿ������ͻ�Ϊ�������û��ǲ�����ʱ��������װж��
�æ����һ�ԵĻ�ơ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"wangnan1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dai" : 1,
        ]));


//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

