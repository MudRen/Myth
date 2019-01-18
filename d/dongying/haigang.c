
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
这里是去东瀛岛的必经之地，这里来往的人并不多，
偶尔你能看到一些来网东瀛和西游世界的商人，
如果你想出海，舟船(chuan) 十分方便。
LONG );
	set("exits", ([
                "west" : "/d/southern/wutai/guandao3",
	]));
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
	]));
	set("objects", ([
		__DIR__"npc/chuanfu": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", 1);
	setup();
//	replace_program(ROOM);
}
