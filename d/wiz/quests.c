 // Room: /d/wiz/quests.c

inherit ROOM;
#include <ansi.h>

void create()
{
    set ("short","���������������");
	set("long", @LONG

 ��������ɮר�Ÿ������ص��ֵܿ���ķ��䣬
ּ�ڸ�����ṩһ���㿪��·�ĳ����������
������ĵ�����

�ڿ��е�����£��һ���һЩ�����ܼ������㡣



LONG
	);
set("item_desc" , ([ /* sizeof() == 1 */
"east": "�������������ƣ�ʲôҲ���������\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : WIZARD_ROOM,
   "down" : "/d/wiz/entrance",
]));
  set("objects", ([ /* sizeof() == 1 */
]));
        set("no_time",1);
	set("no_clean_up", 0);
	set("post_limit", 1);

	setup();
       call_other("/obj/board/seng_b", "???");
}
void init()
{
       add_action("do_exert", "exert");
       add_action("do_exert", "perform");
       add_action("do_exert", "kill");
       add_action("do_exert", "fight");
       add_action("do_exert", "ji");
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


