// Room: /d/death/walk.c
inherit ROOM;

void create ()
{
  set ("short", "�Ľ���Ұ");
  set ("long", @LONG

��ΧʲôҲû�У�������һ����Ӱ��������ֻ�����صķ���������
��������Ұ��������߿�Х���߸ߵ�Ұ�����ҡ�ڣ����з�������
���������������������洩�С�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"new-out2",
  "west" : __DIR__"new-out3",
  "north" : __DIR__"new-out8",
  "south": __DIR__"new-out7",
]));
  set("hell", 1);

  setup();
}
