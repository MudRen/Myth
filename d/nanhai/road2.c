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
// 14             "/d/calvin/usr/trhy1" : 1,
]));

  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "southup" : __DIR__"road1",
]));

  setup();
}
