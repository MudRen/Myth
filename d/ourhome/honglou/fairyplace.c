// Room: /u/hkgroup/fairyplace
inherit ROOM;

void create ()
{
  set ("short", "̫��þ�");
  set ("long", @LONG

����������˭���뻪�㾳��ǧ�ŷ�����ҵ��

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"main",
]));
  set("objects", ([
           __DIR__"npc/fairygirl": 1,
]));

  setup();
}
