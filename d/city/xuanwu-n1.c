//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ�򱱷���Զ
Զ���ܿ����ʹ��ĳ����š����������̨�������ǹ��Ӽࡣ
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"north" : "/d/huanggong/chaoyangmen",
                "west" : __DIR__"tianjiantai",
                "east" : __DIR__"guozijian",
                "south" : __DIR__"xuanwu-n0",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//	   __DIR__"npc/japan":2,
//	   __DIR__"npc/japan2":2,
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

