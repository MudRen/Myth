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
  "east"   : __DIR__"tgqn7",
  "west"   : __DIR__"tgqn5",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
