// Room: /moon/road.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�߷����ƣ��������ף����ִ�����ʱ�㱸��Գ�����������۾�Ծ��
ʵ������֮�ɶ���
LONG);

  set("outdoors", __DIR__"");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"road4.c",
  "eastdown" : __DIR__"road2.c",
]));

  setup();
}







