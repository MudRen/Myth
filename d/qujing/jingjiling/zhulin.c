#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����м���������֣�ż������÷������Ʈ�㡣�ּ���˫��к
��ʯ���У����齦�������˹ǡ���������һ������֮���š���
������д�������֮��Ȼ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhu" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"songlin",
  "northwest": __DIR__"xinglin",
  "northeast" : __DIR__"bolin",
]));

  setup();
}


