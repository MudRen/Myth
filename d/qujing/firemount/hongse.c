// rewritten by snowcat on 4/11/1997
// room: hongse

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "��ɫׯԺ");
  set ("long", @LONG

��һ��������������һƬ��ɫ�����߸ǵķ��ᣬ��ש����ԫǽ����
�����ȣ������齣����Ǻ�ġ�

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luzhou2",
]));

  setup();
}
