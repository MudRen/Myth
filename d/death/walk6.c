// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

����һ�����������ȣ�û��ʲô���߶�����ΧҲû��ʲô������һ��
���Ǿ����ĵġ�������һ������שʯ�Ĺ������һ������֮�С�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"walk5",
  "northup" : __DIR__"cuiyun",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tong2" : 1,
  __DIR__"npc/tong1" : 1,
]));

  setup();
}
