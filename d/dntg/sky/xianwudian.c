//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����");
set("long", @LONG
�������������ܻ��������ߴ���ΰ����
������������߰��������ûʡ�    
LONG );


set("exits", ([
  "north"   : __DIR__"weiyuegong",
  "south"   : __DIR__"xuanyuantang",
]));


set("objects", ([
]));



setup();
}
