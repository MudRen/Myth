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
//  "east"    : "/d/dntg/laojun/gate",
  "south"   : "/d/dntg/sky/yunlue3",
  "north"   : __DIR__"wmj5",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
