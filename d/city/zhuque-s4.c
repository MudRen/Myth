//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","��ȸ���");
        set ("long", @LONG

��ȸ������̼��ڶ࣬���СС�ĵ��̱��ڶ��������������൱�ĺ�
�����㡣������ʯ��·ֱͨ�ϱ�����ͨ���ʹ��ĳ����ţ����Ͽ�ң
�������������ɽ������һ��С·�����ɵģ�����ͨ�����Ͻ֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/nanchengkou",
                "north" : __DIR__"zhuque-s3",
                "west" : __DIR__"beiyin5",
                "east" : "/d/eastway/wangnan5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/penglai/npc/laitou" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

