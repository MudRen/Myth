// Room: /d/qujing/wudidong/road1.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG

����һ������ʯ��С·������ũ���������ڵ��µ�ȥ�ˣ�·��һ��
����Ҳû�У�ֻ�м���Сͯ��Ϫ��׽����Ϸ��·���������أ�ʱ��Ұ
������ֻС��СѼ������ȥ��һ��Ұ��ҡ��β�����˹����������ţ�
�����˿�ȥ��
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dog" : 1,
  __DIR__"npc/kid" : 2,
]));
	set("outdoors", "1");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"temple-qiandian",
  "north" : __DIR__"dibaohouse",
  "west" : __DIR__"road2",
  "east" : __DIR__"entrance",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
