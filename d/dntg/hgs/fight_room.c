//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "���������䳡");
set("long", @LONG
    
���������䳡���Ĺ��佫���������£�����ƫ�Խ�У������������
�����С����Ҿ�ʿ����ȫװ�ߴ����ָ�ִꪶ������м�һ���б�
ʿ�������ݵĴ��������С�
LONG );


set("exits", ([
  "north"   : __DIR__"aolaifighting",
  "south"   : __DIR__"bingqiku",
]));


set("objects", ([
   __DIR__"npc/wushi"   : 4,
]));



set("outdoors", 1);

setup();
}
