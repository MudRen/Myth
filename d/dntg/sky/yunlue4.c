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
  "west"   : __DIR__"yunlue3",
  "east"   : __DIR__"dongtian",
]));


set("objects", ([
]));



set("outdoors", 1);

  create_door("east", "������", "west", DOOR_CLOSED);
        set("no_clean_up", 0);

setup();
}
