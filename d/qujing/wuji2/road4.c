// Room: /moon/road.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

·����ǧ���ϰأ���������ȽȽ��������򣬺���һ��ɫ�Բԡ���
������������������������һ������
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"road3",
  "northwest" : __DIR__"temple",
  "west" : __DIR__"road5.c",
]));

  setup();
}







