#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

Сɽ���ߣ�ɽ����ľ���࣬�Ե÷ǳ��о����������ߴߴ����
�Ľ��ţ�ʱ��ʱ·�ߵĲݴ��дܳ�ֻҰ�ã�����ֻ��ȸ��
��������һ��Сɽ֮��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"to-baoxiang2",
  "eastup" : __DIR__"to-baoxiang4",
]));

  setup();
}

