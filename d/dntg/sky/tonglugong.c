//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�¬��");
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"bishagong",
  "north"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
