// Room: /d/death/walk.c
inherit ROOM;

void create ()
{
  set ("short", "�Ľ���Ұ");
  set ("long", @LONG

��ΧʲôҲû�У�������һ����Ӱ��������ֻ�����صķ�����
������������Ұ��������߿�Х��
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"inn2.c",
  "west" : __DIR__"inn1",
  "north" : __DIR__"gate",
]));
  set("hell", 1);

  setup();
}
