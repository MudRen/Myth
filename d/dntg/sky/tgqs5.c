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
"west"   : __DIR__"nantian",
"east"   : __DIR__"tgqs6",
]));


set("objects", ([
   __DIR__"npc/leigong" : 1,
]));



set("outdoors", 1);
setup();
}
