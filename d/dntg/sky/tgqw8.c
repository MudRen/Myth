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
  "north"   : __DIR__"tgqn1",
  "south"   : __DIR__"tgqw7",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
