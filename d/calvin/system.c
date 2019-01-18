// Room: /d/wiz/system.c

inherit ROOM;
#include <ansi.h>

void create()
{
  set ("short","烟雨阁楼");
	set("long", @LONG

这里是兰陵有名的一处大阁楼，当然也是兰陵城市的公告处。


LONG
	);
set("item_desc" , ([ /* sizeof() == 1 */
"east": "房子里云雾缭绕，什么也看不清楚。\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/wiz/wizroom",
  "west" : "/d/calvin/kezhan2",
]));
  set("objects", ([ /* sizeof() == 1 */
//  "/d/wiz/obj/xmastree" : 1,
]));
        set("no_time",1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_magic", 1);
	set("post_limit", 1);

	setup();
        call_other("/obj/board/system_llb", "???");
}
void init()
{
  	add_action("do_exert", "exert");
}
int do_exert(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("天上传来一声怒嚎：“$N想运功？没门！要练功出客栈去！”\n",who);
        return 1;
}


int valid_leave(object me, string dir)
{
//		if(me->query("id")=="beavis") return ::valid_leave(me, dir);
		  //temp access for future wiz.

		if( dir=="east" && !wizardp(me) )
			return notify_fail("那里只有巫师才能进去。\n");
		return ::valid_leave(me, dir);
}


