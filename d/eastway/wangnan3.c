inherit ROOM;

void create ()
{
        set ("short", "���Ͻ�");
        set ("long", @LONG

���ǵ����Ͻֵ�·��㣬��Χ��ס�������Ǯ�˼ң�·���Զ���Щ��
լ��Ժ��Ժǽ������·��������ʯ��·�����ų��е���������֦���
Ʈ�ڲ������������˲��࣬����һ��С·��֪ͨ��η���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"wangnan2",
                "west" : __DIR__"wangnan4",
		"southeast" : __DIR__"guandao2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/obj/book/misc" : 1,
        ]));


        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

