//by dewbaby
//xiaolu1

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

奇花异草在小路两边随风飘摇，绚烂盛开的模样让你
心神陶醉。春冬秋夏，此处花开永不落。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaolu3",
   "west" : __DIR__"wyg",
]));
   set("objects",([
      "/d/wizz/dewbaby/obj/haitang.c":1,
      "/d/wizz/dewbaby/obj/shaoyao.c":1,
  ]));

  setup();
}


