// Room: /4world/houshan2
inherit ROOM;

void create ()
{
  set ("short", "��ɽ����");
  set ("long", @LONG

�㶥����ͷ������Ұ��֭�����������У���һȺ�����ֵ�
֨֨�ҽС�������Ȼ��̫ͬ����Ĵ��������ڲ�ͣ���ø�
�ָ�����Ұ�����㡣������һ����ɽ��С·������͸����
�Կ��Կ���һС��ƽ�ء�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/monkey2" : 1,
  __DIR__"npc/monkey1" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houshan3",
  "southdown" : __DIR__"houshan1",
]));

  setup();
}
