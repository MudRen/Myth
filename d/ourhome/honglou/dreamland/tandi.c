
#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "̶��");
  set ("long", @LONG

����������ˮ̶̶�ף�����ˮ���ܲ�������ˮ������Ʈ�ڡ�
LONG);
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/jiaolong" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"shuitan",
]));
  setup();
}
