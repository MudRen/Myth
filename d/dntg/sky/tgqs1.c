//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�칬��ǽ");
set("long", @LONG
    
�ߴ���ΰ���칬��ǽ���������������ߣ�����
��ǽ��ȥ������һ�ڣ��岽һ�ڡ��䱸ɭ�ϡ�
LONG );


set("exits", ([
"east"   : __DIR__"tgqs2",
"north"   : __DIR__"tgqw1",
]));


set("objects", ([
    __DIR__"npc/spring-gongcao" : 1,
]));



set("outdoors", 1);
setup();
}
