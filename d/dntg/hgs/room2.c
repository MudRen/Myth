// Room: /d/4world/room2.c
inherit ROOM;

void create ()
{
  set ("short", "��լ");
  set ("long", @LONG

һ��СС����լ����ɨ�ĸɸɾ������Ҿ㲻�Ǻܺã������۵ľ�ֻ
��һ���������ϰ��Ŵ�����ǽ�߶��������ˣ����»���Щ���
��ɵ���𣬿����������ǿ�������ı����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"east2",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhu2" : 1,
  __DIR__"npc/zhu1" : 1,
]));

  setup();
}
