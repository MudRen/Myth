//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "���۱���" );
        set ("long", @LONG

����һ������������������������֮�ϣ��������Ĵ�������һʮ��
λ��շ������ԡ���ǰ�Ĺ�̨����������Ů����������Ʒ��д����
Ը����ֽ����̨��һ��С�䣬װ���ǹ���Ľ�����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"huashengsi",
                "east" : __DIR__"fangzhang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


