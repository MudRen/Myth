//beimenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "������");
        set("long", @LONG
 
���������С�
LONG
        );
 
        set("exits", ([
                "north" : __DIR__"beitian",
        ]));
 
        create_door("north", "������", "south", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
