// Room: /u/hkgroup/pavilion
inherit ROOM;

void create ()
{
  set ("short", "�߷�ͤ");
  set ("long", @LONG

�����Ƶ��������ݴ䣬��������һ���㡣

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wux",
  "south" : __DIR__"path1",
  "north" : __DIR__"yard1",
  "down" : __DIR__"kat",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
