
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����ǡ���ȵ�������С·��
LONG );
	set("exits", ([

		"north" : __DIR__"road1",
		"south" : __DIR__"gate",
	]));
 	set("objects", ([
	]));
	set("outdoors", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
