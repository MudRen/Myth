//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
          set ("short",HIR "����ի" NOR);
        set ("long", @LONG

����������ֵ������ݣ�����˿׷����¸����ļ����ؼ���
��˵��ֵ���ǲ��Ŷ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                  "out" : __DIR__"zoulang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                    __DIR__"npc/seller" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


