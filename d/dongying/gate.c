
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����ǡ���ȵ����������š�
LONG );
	set("exits", ([

		"north" : __DIR__"road2",
		"south" : __DIR__"xiaodao3",
	]));
 	set("objects", ([
	]));
	set("outdoors", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
