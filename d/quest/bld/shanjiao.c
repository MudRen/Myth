//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ��");
        set ("long", @LONG

��ɽ��Ȼ����һ�㣬վ��ɽ�ž��ܸо���������Ҫ�����Ͽ���ɽ
ʯ��ᾣ���ľ�����������������ɽ����һ����ͬ��
LONG);

        set("exits", 
        ([ //sizeof() == 2
                "west" : __DIR__"shanbian1",
             "southdown" : "/d/westway/jiayu",
                "east" : __DIR__"shanbian2",
                "north": __DIR__"shanlu1",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

