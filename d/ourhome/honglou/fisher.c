// Room: /u/hkgroup/fisher
inherit ROOM;

void create ()
{
  set ("short", "����̨");
  set ("long", @LONG

����̨���Ϸ���һ�������㡣

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"village",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
