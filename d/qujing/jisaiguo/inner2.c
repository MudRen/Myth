#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

Ժ�е��ƿ�����ǽ�ߵĹ������죬֦��Ҷ�ܡ�����һ����ש�̳�
��С·ֱͨ�����Ĵ��۱������һʽ����שС�ᣬ��ϡ����
�������յ�������ֻ�Ƕ��˼���������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/heshang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inner3",
  "south" : __DIR__"inner1",
  "east": __DIR__"jing",
  "west": __DIR__"xiang",
]));

  setup();
}

