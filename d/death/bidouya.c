inherit ROOM;

void create ()
{
  set ("short", "�ڶ���");
  set ("long", @LONG

�������κ��ţ��ź�һ���շ壬���������ȷ硣�ϱ��ǽ���ɽ
��һ���³ǣ�����������������Ҿ�������ɣ�����������
��������ٲ���֮�ض����޳���֮ʱ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pingyang",
  "north" : __DIR__"naiheqiao",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/duanzhu" : 1,
]));

  setup();
}
