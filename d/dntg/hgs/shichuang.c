//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ʯ��");
set("long", @LONG
    
һ�ų�����ʯ����
LONG );


set("exits", ([
"out"   : __DIR__"shifang",
]));


set("objects", ([
]));



set("sleep_room", 1);
setup();
}
