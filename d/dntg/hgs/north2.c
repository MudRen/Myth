// Room: /d/4world/north2.c
inherit ROOM;

void create ()
{
  set ("short", "���ҽ�");
  set ("long", @LONG

���ǰ�����������һ���֣��������ɡ����еĸ����̼Ҷ����
�ˣ���ׯ�̺ţ����ݿ�ջ���ϡ���������ӵ��������Ҳ������װ
���ε����ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"northgate",
  "south" : __DIR__"north1.c",
  "west" : __DIR__"bank.c",
  "east" : __DIR__"pownshop.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/monk" : 1,

]));

  set("outdoors", __DIR__"");

  setup();
}
