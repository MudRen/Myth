//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��ĸ��");
set("long", @LONG
    
һ�����Ĵ�֣���ֱ����չ��ȥ����������ס��
�����칬����Ȩ�Ƶ��ˣ�·�ľ�ͷ���������԰��
LONG );


set("exits", ([
  "north"   : __DIR__"wmj3",
  "south"   : __DIR__"wmj1",
  "east"   : "/d/dntg/yunlou/gate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
