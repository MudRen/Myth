// Room: /d/jjf/kitchen_road1.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG
һ������������С·��·���̲ݼ�ϡϡ��������˼����¼���
����ֻС��СѼ����������ʳ���ϱ��Ǻ�ԺС��԰����ʱ��������
���ﻨ�㡣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kitchen_road2",
  "northwest" : __DIR__"dining_room",
]));
  set("outdoors", 1);

  setup();
}
