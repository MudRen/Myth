// Room: /u/mimi/zhuziguo/road5  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

·����ǧ���ϰأ���������ȽȽ��������򣬺���һ��ɫ�Բԡ���
����������������������������һ������
LONG);

  set("outdoors", __DIR__"");
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"hilltop",
  "east" : __DIR__"road4",
  "north" : __DIR__"temple.c",
  "westdown" : __DIR__"road6",
]));

  setup();
}

