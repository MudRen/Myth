//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�ּ�С·");
set("long", @LONG
    
����ɽ�е�һ���ּ�С·��������پ��ᣬ��ľ���죬����
���У�ֻ��һЩ���������䵴����ȥ������ɽɽ����ΰ����
�վ�����ɽ�����߲��������������Ϻܿ�͵�ɽ���ˡ�
LONG );


set("exits", ([
  "northup"   : __DIR__"entrance",
  "westdown"   : __DIR__"up1",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
