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
  "south"   : __DIR__"dongtian",
  "north"   : __DIR__"tgqe6",
]));


set("objects", ([
    __DIR__"npc/tianding3" : 1,
]));



set("outdoors", 1);

setup();
}
