//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ǬԪ��");
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"shenpinggong",
  "north"   : __DIR__"lingxiao",
]));


set("objects", ([
]));



setup();
}
