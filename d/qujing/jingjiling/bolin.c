#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����֮�йŰ�ɭɭ����ȥ��ľ���а���֮�䣬ֱͦ�޳�����Ƥ��
�з�˪ż�֣�֦Ҷ�ϵ������ܡ���ľ���������ܵ����ϣ���֮��
������һ����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/bo" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"xinglin",
  "northwest": __DIR__"shiya",
  "southwest" : __DIR__"zhulin",
]));

  setup();
}


