// Room: /d/jjf/kitchen_road2.c

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
  "south" : __DIR__"kitchen",
  "northwest" : __DIR__"kitchen_road1",
]));
  set("outdoors", 1);

  setup();
}
