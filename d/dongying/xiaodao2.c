

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到路
的尽头。两旁百花争艳。令人留连忘返。南边好象有香味散发出来。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"xiaodao1",
		"east" : __DIR__"xiaodao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", 1);
	setup();
	replace_program(ROOM);
}
