#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯɽ");
  set ("long", @LONG

��ʯɽ����ʯ��أ����С�ĵ������ǡ����ϼ����������ľ
Ψ�к���������ɽ������һ�ź��ơ�Զ���̲�̶�����Թ�������
��«����ѩ��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"shigang1",
  "northdown" : __DIR__"shigang2",
]));

  setup();
}

