#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "·��");
  set ("long", @LONG

�������зǳ��ķ�����·�ܵ�¥̨���ʣ������ͷס�ֻ��������
���У���ֳͨ�ƣ������˵��¹�¡�أ������񸻺�����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shusheng" : 1,
  __DIR__"npc/qiaofu" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"westgate",
  "east" : __DIR__"westmarket",
  "south" : __DIR__"west1",
]));

  setup();
}

