// Room: /u/mimi/zhuziguo/road6  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ֻ����ɽ����Ρ�룬��Χ�վ����Ź������̴�ǣ��ݴ����������ᡣ
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"road7",
  "eastup" : __DIR__"road5",
]));

  setup();
}

