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
  "south"   : __DIR__"wmj4",
  "north"   : __DIR__"wmj6",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
