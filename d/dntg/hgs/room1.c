// Room: /d/4world/room1.c
inherit ROOM;

void create ()
{
  set ("short", "��լ");
  set ("long", @LONG

�⻧�˼��ڳ���Ҳ��Ƚϸ�ԣ���ˡ������˳��꾭�����⣬������
�����ּ�����ͬ������˼�һ�������﹩���Ϻ������͹���ү��
����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"east2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 1,
  __DIR__"npc/kid" : 1,
]));

  setup();
}
