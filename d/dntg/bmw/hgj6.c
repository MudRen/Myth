//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
    
���������칬���ر����أ�������ֱͨ�칬��Ӫ��
����פ���ż�ʮ���������Ӫ�Ա������������
����䡣
LONG );


set("exits", ([
  "north"   : __DIR__"zhanyaotai",
  "south"   : __DIR__"hgj5",
  "west"   : __DIR__"gate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
