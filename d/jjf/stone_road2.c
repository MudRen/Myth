// Room: /d/jjf/stone_road2.c

inherit ROOM;

void create ()
{
  set ("short", "ʯ��·");
  set ("long", @LONG
С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ�����
�ÿ���·�߳�����ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ���
�������������ܵ�������
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"sw_garden",
  "south" : __DIR__"main_cabinet",
]));

  setup();
}
