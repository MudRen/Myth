//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��ԯ��");
set("long", @LONG
    
һ���������Ĵ��ã���ͨ�˴�ı����ɷ��裬
װ�κ�����һ�Ӷӳֵ���������ʿ������������ȥ
�ò����磮
.
LONG );


set("exits", ([
"west"   : __DIR__"baihudian",
"east"   : __DIR__"qinglongdian",
"north"   : __DIR__"xianwudian",
"south"   : __DIR__"zhuquedian",
]));


set("objects", ([
]));


setup();
}
