// Room: /u/mimi/zhuziguo/road7  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ���϶�Ħ���������ҷ·�����������̶��ʱ�ŵùȿ���Գ����
�����У�ÿ�����ɼ��ড�ԶԶ�Ŀ��Կ���ɽ��¥̨������������ء�
LONG);

  set("outdoors", __DIR__"");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"road6",
  "westdown" : __DIR__"street1",
]));

  setup();
}
