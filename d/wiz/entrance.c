// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short","��¥����");
        set("long", @LONG

������轲�����õĲ;߶��ǴӾ������������ڵ����ζ��Ǻ�ľ�ģ�
�ڹ���֮�·���������Ĺ����ƴ���ȥ�����������ľ����۵ס�
һȺ�ƿ��Ʊ���յ�����ȵ����֡�
LONG);

        set("exits", ([
		"down" : "/d/city/kezhan",
                "south" : "/d/city/liwuroom",
                  "east" : "/d/wiz/system",
// 23                  "up" : "/d/city/xqt",
               "up" : "/d/wiz/quests",
                "west" : "/d/wiz/entrance3",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
 //       set("valid_startroom", 1);

  set("objects", ([ /* sizeof() == 1 */
//        "/u/stey/npc/seng" : 1,
]));
        setup();
          call_other( "/obj/board/sjsh_ah", "???" );
}
/*
int valid_leave(object me, string dir)
{
  	
	if(me->query("id")=="clock") return ::valid_leave(me, dir);
	if(me->query("id")=="net") return ::valid_leave(me, dir);
	if(me->query("id")=="weiqi") return ::valid_leave(me, dir);
	//temp access for future wiz.

        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
        object ob;
        string s;

        if( ob = find_player(arg) ) {
                if( ob==this_player() )
                        return notify_fail("��Ҫ����Լ���\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) +
"�Ѿ����ˣ�����һ��ɡ�\n");
                if( wizardp(ob) )
                        return notify_fail("�㲻�ܼ����ʦ��\n");
                tell_object(ob, HIW + this_player()->name(1) +
"������Ǹ������ˣ��������һ��СС�Ĳ��顣\n" NOR);
                ROBOT_CHECK->test_me(ob);
                write("Ok. �Ѿ������ٵĶ�����ȥ�����顣\n");

write("Ϊ�˱��������û������Ҽ��ɧ�ű��ˣ�����Ҳ������ͬ�Ĳ��顣\n");
                ROBOT_CHECK->test_me(this_player());
                log_file("robot_accuse",
                        sprintf("%s accused %s on %s.\n",
this_player()->query("id"), ob->query("id"), ctime(time())));
                return 1;
        }
        return notify_fail("Ŀǰ���ϲ�û����λ��ҡ�\n");
}
*/
void init()
{
    add_action("do_exert", "exert");
}
int do_exert(string arg)
{
        object who = this_player();
       object me = this_object();
                tell_object(who, "������ʱ������ʹ����������\n");
          return 1;
}
