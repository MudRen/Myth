//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���Ӽ��Ժ");
        set ("long", @LONG

���Ӽ��ǹ��������߼��˲ŵĵط����Ƴ���ѧ���Ũ�������ﲻʱ��
�Կ�������������ѧ��ģ�����˴���������ʲô���⣬����һЩ����
��������üͷ�Ҵ��߹���������˼����ʲô���⡣
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"xuanwu-n1",
                "east" : __DIR__"guozi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiucai1" : 1,
		__DIR__"npc/xiucai2" : 1,
]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

