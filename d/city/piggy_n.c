inherit __DIR__"piggy.c";
#include <ansi.h>

void create()
{
    ::create();

    set ("short","������");
    set("exits", ([
        "south": __DIR__"club3",
    ]) );
}
