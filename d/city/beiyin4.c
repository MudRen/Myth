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
�����м�С�ƹݣ������Ǽ����ꡣ
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"jiuguan",
		"west" : __DIR__"beiyin3",
                "southeast" : __DIR__"beiyin5",
		"east" : __DIR__"liangdian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/liumang" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


