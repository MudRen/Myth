//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

����һ��������������ͨͨ����լ��С������ʵ���ͣ���ˣ��Ҿ�
��Ȼ˵���ϸ�ԣ����Ҳ������ʳ�����в�û��ʲô�õİ��裬ľ����
�Ĳ���ƿ�в��˼���Ұ����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"west" : __DIR__"beiyin1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dog" : 1,
		__DIR__"npc/girl" : 1,
		__DIR__"npc/liyu" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



