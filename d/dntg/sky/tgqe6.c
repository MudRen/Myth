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
  "south"   : __DIR__"tgqe5",
  "north"   : __DIR__"tgqe7",
]));


set("objects", ([
    __DIR__"npc/tianding4" : 1,
]));



set("outdoors", 1);

setup();
}
