//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "��������");
        set("long", @LONG

�칬��������䲻����ȴҲС�����ǡ����м�һ����
��(bian)���鼸�����֣���ǰ�����������Ѳ�Σ�ż��
������������������׳��˻������
LONG);
set("item_desc",(["bian":"
       ***********************
       **      �����       **
       ***********************\n"
]));

 
        set("exits", ([
                "east" : __DIR__"hgj6",
                "west" : __DIR__"zoulang",
        ]));
 
        set("objects", ([
		__DIR__"npc/jianguan": 2,
        ]));
 
        create_door("west", "С����", "east", DOOR_CLOSED);
        set("no_clean_up", 0);

        set("outdoors", 1);

        setup();
}
