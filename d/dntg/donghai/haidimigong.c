//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����Թ�");
set("long", @LONG
    
����ˮɫ��Ļ�����������Χ�ѿ���������ˡ�ż�а���Ϯ������
��������������Ĵ�����Щ�߸ߵĺ��ݣ����������ͷ���ڵ�һ˿
��âҲû���ˡ�
LONG );


set("exits", ([
  "north"   : __DIR__"maze1",
]));


set("objects", ([
]));



setup();
}
