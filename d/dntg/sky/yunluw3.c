//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��·");
set("long", @LONG
    
̤�����������칬��·������Ʈ�������ƣ������˼�ũ��
��Ʈ����������̣����˱����Ŀ�������
LONG );


set("exits", ([
  "east"   : __DIR__"yunluw2",
  "west"   : __DIR__"yunluw4",
  "north"   : "/d/dntg/bmw/hgj4",
  "south"   : "/d/dntg/bmw/hgj3",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
