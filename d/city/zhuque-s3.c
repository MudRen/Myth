//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��ȸ���");
        set ("long", @LONG

��ȸ������̼��ڶ࣬���СС�ĵ��̱��ڶ��������������൱�ĺ�
�����㡣������ʯ��·ֱͨ�ϱ�����ͨ���ʹ��ĳ����ţ����Ͽ�ң
�������������ɽ�������Ǽ�ë���꣬�����Ǹ�Ьñ�ꡣ
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"zhuque-s4",
                "north" : __DIR__"zhuque-s2",
                "west" : __DIR__"maohuo",
                "east" : __DIR__"xiemao",
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

