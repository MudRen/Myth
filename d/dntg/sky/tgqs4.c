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
"east"   : __DIR__"nantian",
"west"   : __DIR__"tgqs3",
]));


set("objects", ([
   __DIR__"npc/yuntong" : 1,
]));



set("outdoors", 1);
setup();
}
