#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "«����");
  set ("long", @LONG

����«������������һ���Թ���ǰ�����Ҷ���һ�˶�ߵ�«
�ݣ�������������˱粻�巽λ���������«��մ������
���ǡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/luniang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"luhua2",
  "east" : __DIR__"luhua8",
  "north" : __DIR__"luhua6",
  "south" : __DIR__"luhua4",
]));

  setup();
}

