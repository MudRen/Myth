#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

Сɽ���ߣ�ɽ����ľ���࣬�Ե÷ǳ��о����������ߴߴ����
�Ľ��ţ�ʱ��ʱ·�ߵĲݴ��дܳ�ֻҰ�ã�����ֻ��ȸ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/lingxuzi" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"to-baoxiang3",
  "southeast" : __DIR__"to-baoxiang5",
]));

  setup();
}

