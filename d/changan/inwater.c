inherit ROOM;

void create ()
{
  set ("short", "��ˮ");
  set ("long", @LONG

��Χ��������ĺ�ˮ�������ܵľ�ɫ����������ڳ������ϣ���
ˮ֮�У���ˮ�峺���ף�Զ�����м���С����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eside1",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/d/sea/npc/long7.c" : 1,
]));

  setup();
}
