//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��");
set("long", @LONG
    
��������ʯ�����̵أ���������ʱ��л֮�ɻ���ݣ���طҷ���
�������з�����ɫ��Ʈ�㡣��Χ���������¥���������
�̲���
LONG );


set("exits", ([
  "west"   : __DIR__"gate",
  "north"   : __DIR__"yunlou",
  "south"   : __DIR__"taizifu",
]));


set("objects", ([
    __DIR__"npc/tong-nan" : 1,
]));

  create_door("west", "��¥����", "east", DOOR_CLOSED);


setup();
}
