//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
    
�칬��һ��ƫ��������������֮ǰ���ڴ�ЪϢ��
ֻ�������ı����������ƷǷ���
LONG );


set("exits", ([
  "west"   : __DIR__"xuanyuantang",
  "east"   : __DIR__"xinyuegong",
]));


set("objects", ([
]));



setup();
}
