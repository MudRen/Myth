// Room: /d/4world/east2.c
inherit ROOM;

void create ()
{
  set ("short", "��Է��");
  set ("long", @LONG

������û��ʲô�����ˣ���Χɢ���ż�ʮ��ƽ�񡣷��ݾ��ǰ�ǽ
���ߣ�������ʮ�ֵ�ˬ������Щ�˼һ�����ǰ��������Щ�Ϲ���
�ˣ�Ȧ��ЩС��СѼ������������������Ϸ��ż��΢�����Щ��
Ҷ���ƺ�����Ʈ�衣
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kid1" : 1,
  __DIR__"npc/kid" : 1,
]));
  set("outdoors", "/d/4world");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room2.c",
  "north" : __DIR__"room1.c",
  "west" : __DIR__"east1",
  "east" : __DIR__"guchang.c",
]));

  setup();
}
