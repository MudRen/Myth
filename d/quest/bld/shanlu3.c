//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��ɽ֮��");
        set ("long", @LONG

һ���������۵�С·������ֻͨ��ɽ�ϣ�������·���ͣ���̫��
�ߡ������ǵ��Ұ��������С�ݡ�
LONG);

        set("exits", 
        ([ //sizeof() == 2
                "west" : __DIR__"shanlu4",
                "east" : __DIR__"shanlu2",
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

