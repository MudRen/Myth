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
  "west"   : __DIR__"yunlun2",
  "east"   : __DIR__"yunlun3",
  "north"   : __DIR__"jiashan",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
