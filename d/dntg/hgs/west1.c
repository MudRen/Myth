// Room: /d/4world/west1.c
inherit ROOM;

void create ()
{
  set ("short", "��ܾ��");
  set ("long", @LONG

��ܾ�ֿ��Ľֵ�������ʯ�壬ż����ƥ�۹���������ʯ����
�����������������߾�ͨ�������ģ�ԶԶ�ɼ������ع㳡
�͹㳡�еĴ��켰ʯ̨���ϱ��Ǽ�իԺ���Ǹ������᷹�ĵط���
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"huofang.c",
  "south" : __DIR__"zhaiyuan.c",
  "west" : __DIR__"west2.c",
  "east" : __DIR__"center",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid" : 1,
  "/d/city/npc/dog":1,
]));

  set("outdoors", "/d/4world");

  setup();
}
