// Room: /d/4world/school1.c
inherit ROOM;

void create ()
{
  set ("short", "������ݴ���");
  set ("long", @LONG

��������վ��һ���լԺ����ڣ���ֻ�޴��ʯʨ�����ڴ��ŵ���
�࣬һ����ߺ���뵶����ײ��������Ժ���д�����ͨ������������
��������������µĺ������ڲ�����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"school2.c",
  "south" : __DIR__"east1",
]));

  setup();
}
