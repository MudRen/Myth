//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

���ڷ���һ��Ѫ������ǽ�Ϲ����͵ƣ����������ĵƹ�������
����ǰ��ĵ�·��������һ��ʯ�š�
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guaishiya", 
  "northwest" : __DIR__"yongdao3",
  "northeast": __DIR__"yongdao2",
]));
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yao1" : 2,
]));


  create_door("south", "ʯ��", "north", DOOR_CLOSED);


  setup();
}

