// Room: /d/4world/��ܾ��
inherit ROOM;

void create ()
{
  set ("short", "��ܾ��");
  set ("long", @LONG

��ܾ�ֿ��Ľֵ�������ʯ�壬ż����ƥ�۹���������ʯ����
�����������������߾�ͨ�������ģ�ԶԶ�ɼ������ع㳡
�͹㳡�еĴ��켰ʯ̨�������Ǹ�С�������ϱ��Ǽ���լ��
�ſڹ���Щ�첼��
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shiwu.c",
  "north" : __DIR__"tudi.c",
  "east" : __DIR__"west1",
]));
  set("outdoors", "/d/4world");

  setup();
}
