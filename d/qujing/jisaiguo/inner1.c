#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

Ժ�е��ƿ�����ǽ�ߵĹ������죬֦��Ҷ�ܡ�����һ����ש�̳�
��С·ֱͨ�����Ĵ��۱����ϡ���Կ������յ�������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/oldmonk" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inner2",
  "south" : __DIR__"gate",
]));
  create_door("south", "ƫ��", "north", DOOR_CLOSED);

  setup();
}
