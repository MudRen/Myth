//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����");
        set ("long", @LONG

�����ǰ������������ĵط�����������û�¾�ϲ�������ȣ����
ȭ��һ����˵�����������
LONG);

        set("exits", 
        ([ //sizeof() == 2
            //    "north" : __DIR__"xuanya",
                "west" : __DIR__"wunei",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/quest/bld/npc/laozhe" : 1,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

