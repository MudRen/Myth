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
  __DIR__"npc/shaodi" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"baodian",
  "south" : __DIR__"inner2",
  "east": __DIR__"zai",
  "west": __DIR__"cha",
]));

  setup();
}

