//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

����һ��ͨ����ɽ��С·��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xingzhe.c" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guangchang",
  "northdown" : __DIR__"road2",
]));

  setup();
}
