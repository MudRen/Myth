// Room: /d/jjf/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�������ɨ�ĺܸɾ������ڴ����ð���������������˴�����
�Ρ�����Ѿ��������ʰ�߲ˡ�һ��С�������ػص��ܣ�����ڴ���
�֡�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kitchen_road2",
  "southwest" : __DIR__"ne_garden",
]));

  setup();
}
