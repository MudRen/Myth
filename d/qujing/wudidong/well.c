// Room: /d/qujing/wudidong/well.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG

������ˮһֱ�ε��ף��㷢�־�����ʵ�Ǹɵġ�������һ��ʯ�죬��
���ƺ�����յ��ƣ�Ҳ����ʲô��ʥס�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"houyuan",
  "east" : __DIR__"dragon-room",
]));
	set("no_clean_up", 0);
	set("outdoors", 1);

	setup();
	replace_program(ROOM);
}
