//changan city

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set ("long", @LONG

�����ǳ��������ĳ���꣬�����̫̫С�㶼ϲ������������һЩСè��
С����Ҳ��һЩ������Ӣ����������ѡ���ѵ����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"wangnan5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/horseboss" : 1,
	
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

