
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "СԺ");
  set ("long", @LONG

Ժ�����������Χ�ƣ���ʶ��������ͣ�����������֮����Ժ
�а���Щ������ߣ����˼�����������ǽ���и�Сľ���ӡ�
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/girl" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"denglong2",
  "north" : __DIR__"maowu",
]));

  setup();
}

