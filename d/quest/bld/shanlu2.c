//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ·");
        set ("long", @LONG

һ���������۵�С·������ֻͨ��ɽ�ϣ�������·���ͣ���̫��
�ߡ������ǵ��Ұ��������С�ݡ�
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "west" : __DIR__"shanlu3",
                "southdown" : __DIR__"shanlu1",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

