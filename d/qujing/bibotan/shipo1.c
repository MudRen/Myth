#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

��ʯ����ʯ��أ����С�ĵ������ǡ����ϼ����������ľΨ
�к���������ɽ������һ�ź��ơ��򶫿ɿ����̲�̶��һ��̶ˮ
������Χ��ɽ�С�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shanyao" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaolu4",
  "northwest" : __DIR__"shipo2",
]));

  setup();
}

