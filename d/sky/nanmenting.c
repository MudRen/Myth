#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������ţ��Ѿ����Կ���һ�����칬�����߲�ϼ�⣬��������
����������֮�С�һ�����������������������죬�������߸�
��һ����Ҳ��֪�Ǹ�ʲô�õģ��������Լ�������ߵ�����
����֮�����ƺ��˲��١�����С�к�����ɨ�ء�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nantian.c",
  "east" : __DIR__"28xiu-dian.c",
]));

create_door("south", "������", "north", DOOR_CLOSED);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-nan" : 2,
]));

  setup();
}
