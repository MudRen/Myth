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

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shipo1",
  "northup" : __DIR__"shigang1",
  "south" : __DIR__"shipo4",
]));

  setup();
}

