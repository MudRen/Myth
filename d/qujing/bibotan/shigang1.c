#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

��ʯ����ʯ��أ����С�ĵ������ǡ����ϼ����������ľΨ
�к���������ɽ������һ�ź��ơ�������ȥ��ɽ����ɽ����Ǳ�
��̶��΢���������ˮ����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/stone" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shipo2",
  "eastup" : __DIR__"shishan",
]));

  setup();
}

