//Cracked by Roath
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

���߷�¥��գ���������������ɽ������֮�䡣������֮������Ϫкѩ
��ʯ�㴩�ƣ���ʯΪ�����������ӡ�
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"snow.c",
  "north" : __DIR__"ghg_zhengdian.c",
  "south" : __DIR__"road2.c",
  "west" : __DIR__"rain.c",
]));

  set("objects",(["/d/obj/flower/yehua.c":1,]));
  setup();
}






