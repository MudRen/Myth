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
  "north"   : "/d/dntg/sky/yunlue3",
  "south"   : __DIR__"wmj2",
]));

  set("objects",([
   __DIR__"npc/chijiao" :1,
  ]));




set("outdoors", 1);

setup();
}
