// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

  �ݻ���������������ˮ���������������׵�ɽҰ������
�����޵�ɱ����
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"baigushan",
  "westup"    : __DIR__"banshanpo", 
]));

  setup();
}






