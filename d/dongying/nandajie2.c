
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在一条繁华的街道上，向南北两头延伸。南边是南城门，北边通往市
中心，西边是一个树林，东边有个小道。
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xiaodao1",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"shulin5",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
        ]));
	setup();
}
