// Room: /u/none/newtoy/cave
inherit ROOM;

void create ()
{
  set ("short", "ˮ����");
  set ("long", @LONG

��������һ��ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ����ʯ�ʡ�
�м�һ��ʯ��(stone)��������

�����η��д��㣬����ô���˪ѩȫ�޾壬���������š�
������ϼ����ҫ������ÿ��Ѭ�����������㣬�滨�����¡�

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"ironbridge",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
������������ɽ���أ�ˮ�������졣

",
]));

  setup();
}
