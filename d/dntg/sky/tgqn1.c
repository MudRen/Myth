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
  "east"   : __DIR__"tgqn2",
  "south"   : __DIR__"tgqw8",
]));


set("objects", ([
    __DIR__"npc/summer-gongcao" : 1,
]));



set("outdoors", 1);

setup();
}
