#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ҩ��");
  set ("long", @LONG

�����������˺��䣬�и����Ʋ����������⣬����ҩ�̵�����Ҳ
���൱�������ҵĴ��ԭ�ǹ��е���ҽ������������ˢ�ӵġ�
������ץҩ���˰��ż���̤ƽ�ˡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/doctor" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"westmarket",
]));

  setup();
}


