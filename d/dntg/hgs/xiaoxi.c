//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "СϪ");
set("long", @LONG
    
һ���峺���׵�СϪ��ˮ�������������湻�˾���(swim)
��ȥ�ɡ�
LONG );


set("exits", ([
]));


set("objects", ([
  __DIR__"npc/shuishe"   : 1,
  __DIR__"npc/fish"   : 2,
]));



setup();
}


void init()
{
add_action("do_swim", "swim");
}

int do_swim()
{
object me = this_player();

message_vision("$N�ε����ߡ�\n", me);
me->move(__DIR__"xiaoxiqian");
message_vision("$N�ֿ�ˮ�棬���ϰ�����\n", me);
return 1;
}

