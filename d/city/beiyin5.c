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
�����м��ӻ��̣����߾͵�����ȸ��֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"zhuque-s4",
                "northwest" : __DIR__"beiyin4",
		"west" : __DIR__"zahuopu",
		"south" : __DIR__"minju4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


