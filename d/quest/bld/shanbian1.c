//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ��");
        set ("long", @LONG

�����ǻ�ɽ�����ߣ��������߿��Ե���ɽ�����£��ܶ��˶�ϲ��
ȥ�Ǹ����£���˵һ���Ǿ�ɫ�������о��ǿ��ܻᷢ��ʲô���ܣ�
LONG);

        set("exits", 
        ([ //sizeof() == 2
                "east" : __DIR__"shanjiao",
                "westup" : __DIR__"xuanya",
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

