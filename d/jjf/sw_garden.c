// Room: /d/jjf/sw_garden.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
һ��С��԰����Ȼ�Ȳ��ϸ�����Ժ�������ǧ�죬��Ҳ���õ�
���¿��ˡ��ظ�����Ȼ��������֮ʿ���������һ�ʢ�������ճ���
��ɻ����������ջ����ޣ���������һƬ��ѩ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nw_garden",
  "east" : __DIR__"se_garden",
  "southwest" : __DIR__"stone_road2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
