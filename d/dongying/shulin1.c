// shulin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG );
	set("exits", ([
		"north" : __DIR__"shulin1",
		"south" : __DIR__"haigang2",
		"east" : __DIR__"shulin1",
		"west" : __DIR__"shulin2",
	]));
	set("outdoors", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
