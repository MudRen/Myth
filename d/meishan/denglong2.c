
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�཭ˮ����������ң��ˮ��һƬ��ã������С����������ֻҰ
Ѽ����ˮ�����������������м�ʮ����ľ׮�Ӵ�ɵĶɿڣ�ż
�д�ֻͣ���������и�С��壬��ʮ����é�ݷ��ӡ�
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/fefisher" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/meishan/denglong1",
  "east" : __DIR__"denglong3",
  "north" : __DIR__"xiaoyuan",
]));

  setup();
}

