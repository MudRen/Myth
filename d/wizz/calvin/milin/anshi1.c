//Cracked by Roath
//Cracked by Roath
// ajax

#include <room.h>
inherit ROOM;

void create()
{
set("short", "���ְ���");
set("long", @LONG

        ����һ���ܶ��صİ���,��Ϊ���ɭ��
ƽʱ���Ե�����ϡ��,������İ��Ҽ���û����
�ֹ�,�����Եĺ�Ƨ��,�ܰ�ȫ��
LONG );

set("exits", ([
                "enter" : "/d/calvin/milin/anshi",
                "out" : "/d/calvin/milin/anshi",
              "up" : "/d/calvin/milin/bed",

]));
set("objects", ([
]));

create_door("enter", "ʯ��", "out", DOOR_CLOSED);
set("no_clean_up", 0);

setup();
}
