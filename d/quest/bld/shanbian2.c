//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ��");
        set ("long", @LONG

�����ǻ�ɽ�Ķ��棬������������������Ϊ����ûʲô������
��˵���ϻ����й��û��
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "west" : __DIR__"shanjiao",
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

