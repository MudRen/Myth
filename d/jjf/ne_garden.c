// Room: /d/jjf/ne_garden.c

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
  "northeast" : __DIR__"kitchen",
  "west" : __DIR__"nw_garden",
  "south" : __DIR__"se_garden",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
