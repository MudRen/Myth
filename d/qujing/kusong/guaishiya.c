//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

ǰ���Ĺ�ʯ��һ�¸�ǽ����·�ϡ����Ϲ���һ�شص��Ҹ����ܣ�
�󲿷��Ѿ����ƿ�ή������һ�ȴ�ʯ�ţ��ű��и����ʯ�٣�д
�ˡ���ɽ���ɽ����ƶ����˸����֡�
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kusongjian",
  "north" : __DIR__"yongdao1", 
]));

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/xiaoyao" : 2,
  __DIR__"npc/kuairufeng": 1,
  "/obj/zhangmen/huoyun.c": 1,
]));



  set("outdoors",1);
  create_door("north", "ʯ��", "south", DOOR_CLOSED);
  
  
  setup();
}
 

