#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

��ʯɽ����ʯ��أ����С�ĵ������ǡ����ϼ����������ľ
Ψ�к���������ɽ������һ�ź��ơ��ϱ�����ȥ��ɽ��������̶
ˮ���̣���ͬů�������ɽ�С�
LONG);
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shanyao" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"shishan",
  "northeast" : __DIR__"shipo3",
]));

  setup();
}

