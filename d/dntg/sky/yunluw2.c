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
  "east"   : __DIR__"yunluw1",
  "west"   : __DIR__"yunluw3",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
