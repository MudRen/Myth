//Cracked by Roath
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ȣ�����ʯ�������·��������һ����������˵�С
�ݣ����������
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"courtyard.c",
  "south": __DIR__"huilang.c",
  "west" : __DIR__"wangmu_room.c",
]));
  set("objects", ([ 
           __DIR__"npc/fairy4" : 1,
  
        ]));
  setup();
}






