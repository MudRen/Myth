
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG );
	set("objects", ([ ]));
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shulin3",
		"north" : __DIR__"shulin3",
		"east"  : __DIR__"shulin4",
		"west"  : __DIR__"shulin2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
