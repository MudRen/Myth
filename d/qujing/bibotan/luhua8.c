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

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"luhua5",
  "east" : __DIR__"luhua2",
  "north" : __DIR__"luhua9",
  "south" : __DIR__"luhua7",
]));

  setup();
}

