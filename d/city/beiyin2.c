//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

������λ�ڳ�����֮���ϣ�ס�������Щƶ���˼ҡ����ڹٸ����ٹ�
��������ΰ�����ʮ�ֺá���Χ������䣬·���Ӳݴ�����������
���ƵĻ�ɫ������һ˿�������������˴�����������ڣ������ɫ��
�����Ǹ�����ÿڣ���ɭɭ�ģ������м�С�ƹݡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"west" : __DIR__"sanhua",
		"east" : __DIR__"jiuguan",
		"northwest" : __DIR__"beiyin1",
                "south" : __DIR__"beiyin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/thief" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


