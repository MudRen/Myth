//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "����");
        set("long", @LONG

һ���������ȣ���ɹ���ƥ�������ߡ�
LONG
        );
 
        set("exits", ([
                "east" : __DIR__"gate",
                "west" : __DIR__"zhengting",
        ]));
 
        set("objects", ([
                __DIR__"npc/jianfu" : 1,
        ]));
 
        create_door("east", "С����", "west", DOOR_CLOSED);
        set("no_clean_up", 0);


        setup();
}
