//Cracked by Roath
// Room: /d/nanhai/xiaoyuan
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "СԺ");
  set ("long", @LONG

����һ��СԺ��Ժ�б鲼�滨��ݣ����������Ժ��������
������ʵʵ����һ����������֮���ڡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/tidu" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guangchang",
  "west" : __DIR__"zoulang",
  "south" : __DIR__"gate",
  "east" : __DIR__"zoulang2",
]));

create_door("south", "ʯ��", "north", DOOR_CLOSED);
  setup();
}
