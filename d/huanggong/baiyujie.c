// Room: /d/huanggong/guangchang.c
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

һ�����༶��ʯ����ϵ�ڳ��쳡�ͻʹ�����֮�䡣��ʯȫ����
�õĺ�����ÿ�����滹���Ÿ��ַ������ޣ�������棬��֮
�������������������ʿΡȻ����������Ķ��Ź�����Ա��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weishi" : 2,
]));
  set("outdoors", "/d/huanggong");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dadian",
  "southdown" : __DIR__"guangchang.c",
  //"east" : __DIR__"changlang",
]));

  setup();
}
