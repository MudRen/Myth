// Room: /d/wiz/system.c

inherit ROOM;
#include <ansi.h>

void create()
{
  set ("short","�����¥");
	set("long", @LONG

����������������һ�����¥����ȻҲ��������еĹ��洦��


LONG
	);
set("item_desc" , ([ /* sizeof() == 1 */
"east": "�������������ƣ�ʲôҲ���������\n",
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
        message_vision("���ϴ���һ��ŭ������$N���˹���û�ţ�Ҫ��������ջȥ����\n",who);
        return 1;
}


int valid_leave(object me, string dir)
{
//		if(me->query("id")=="beavis") return ::valid_leave(me, dir);
		  //temp access for future wiz.

		if( dir=="east" && !wizardp(me) )
			return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
		return ::valid_leave(me, dir);
}


