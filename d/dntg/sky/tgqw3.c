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
"north"   : __DIR__"tgqw4.c",
"south"   : __DIR__"tgqw2.c",
]));


set("objects", ([
    __DIR__"npc/tianding5" : 1,
]));



set("outdoors", 1);
setup();
}
