// rewritten by snowcat on 4/11/1997
// room: xiaodian

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

���������ϵ�һ��С�꣬������Ʒ�ʹ��ƶ�������һ����������һ��
�����ӣ�������С���Ĵ�������

LONG);

  set("exits", ([
        "south" : __DIR__"luzhou2",
      ]));
  set("objects", ([
        __DIR__"npc/vendor" : 1,
      ]));

  set("valid_startroom", 1);
  setup();
}
