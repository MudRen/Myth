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
"west"   : __DIR__"tgqs5",
"east"   : __DIR__"tgqs7",
]));


set("objects", ([
   __DIR__"npc/dianmu" : 1,
]));



set("outdoors", 1);
setup();
}
