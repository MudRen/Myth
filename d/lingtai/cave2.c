// Room: some place in ��ţ����
// cave2.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

����������Ϣ�������������һ�����У������䲻������
ȴ�������������Ǽ��������Ƕ����ͷ������һЩ��˺��
��Ƭ��ʬ�壮
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youngwolf.c" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"cave1",
]));

  setup();
}
