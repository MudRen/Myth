//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

����һ��ͨ����ɽ��С·����·����Խ��Խ�����ߣ��ֲ�ҲԽ��Խ���ˡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"road4",
  "south" : __DIR__"road2",
]));

  setup();
}
