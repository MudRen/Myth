//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ն��̨");
set("long", @LONG
    
��ʷ�����������Ϊ��罵ħ��Ԫ˧����������ն����ĺ�Ը��
�ķ���ն��̨������һ��߶�ߵ��׭�������ķ�����ػ�����
����ɱ�����ڡ�
LONG );


set("exits", ([
  "south"   : __DIR__"hgj6",
]));


set("objects", ([
  __DIR__"npc/shenbing" : 2,
]));



set("outdoors", 1);

setup();
}
