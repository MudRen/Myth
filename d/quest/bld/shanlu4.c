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
        ([ //sizeof() == 4
                "northup" : __DIR__"shanyao",
                "east" : __DIR__"shanlu3",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

