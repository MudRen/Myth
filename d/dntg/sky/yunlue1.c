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
  "west"   : __DIR__"lingxudian",
  "east"   : __DIR__"yunlue2",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
