// Room: /moon/road.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ���϶�Ħ���������ҷ·�����������̶��ʱ�ŵùȿ���Գ���Ҵ���
�У�ÿ�����ɼ��ড�
LONG);

  set("outdoors", __DIR__"");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road2",
]));

  setup();
}






