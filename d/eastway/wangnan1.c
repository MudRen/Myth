inherit ROOM;

void create ()
{
        set ("short", "���Ͻ�");
        set ("long", @LONG

���ǵ����Ͻֵ�·��㣬��Χ��ס�������Ǯ�˼ң�·���Զ���Щ��
լ��Ժ��Ժǽ������·��������ʯ��·�����ų��е���������֦���
Ʈ�ڲ�����������һ������У�ʱ���������˻���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "southwest" : __DIR__"wangnan2",
                "north" : "/d/city/qinglong-e3",
		"east" : __DIR__"huohang",
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

