
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�཭ˮ����������ң��ˮ��һƬ��ã������С����������ֻҰ
Ѽ����ˮ�����������������м�ʮ����ľ׮�Ӵ�ɵĶɿڣ�ż
�д�ֻͣ����
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/fisher" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : "/d/meishan/guanjiang3",
  "east" : __DIR__"denglong2",
]));

  setup();
}

