// Room: /d/4world/shiwu.c
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

���ڹ��߰�����������������ǽ�ϻ���Щ����֮���ͼ�Ρ���
��������ǳ��������İ����ţ��������浻������ˮ�����
�����յ������ٲ�������Ҳ��˵������������֪�鲻�顣
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aqi" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west2",
]));
  setup();
}
