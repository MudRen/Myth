#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����֮�н��ǹ�������ȥ��ľ���а���֮�䣬ֱͦ�޳�����Ƥ
���з�˪ż�֣�֦Ҷ�ϵ������ܡ���ľ���������ܵ����ϣ���֮
�����һ����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/hui" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast": __DIR__"songlin",
  "east": __DIR__"xinglin",
  "northeast" : __DIR__"shiya",
]));

  setup();
}


