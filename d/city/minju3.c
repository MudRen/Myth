//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

�ⶰ���������Ǻܾ�û���˾�ס�ˣ�ǽ�������µ������ǻҡ�������
���Կ����ʷʵ�����������ȥ��Ժ���Ӳݴ��������������������нС�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"beiyin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/rat" : 3,
		"/d/qujing/wudidong/npc/bianfu" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



