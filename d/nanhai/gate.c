//Cracked by Roath
// Room: /d/nanhai/gate
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�������Ϻ�����ɽ��ɽ�ţ�ɽ����д�ţ�

     ��ƿ��¶����ʢ��б�崹�������ࡣ
     ��٤ɽ�ϴȱ�������������������

�����ɽ���أ��������죡

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhike" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaoyuan",
  "southdown" : __DIR__"shanglu",
]));

  create_door("north", "ʯ��", "south", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

"/obj/board/wall_b"->foo();
}

