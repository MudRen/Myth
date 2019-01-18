// Room: /u/hkgroup/workroom

#include <room.h>
inherit ROOM;
//#include "honglou.h"

void init();
void do_close2();
int do_push(string);
int valid_leave();
string look_door2();
int do_knock2(string);

void create ()
{
  set ("short", "��¥��ַ");
  set ("long", @LONG

��������֮����һ��(bian)������ȴ������ֻ�н���(door)���˳��롣

LONG);

  set("light_up", 1);
  set("no_magic", 1);
//  set("outdoors", "/u/hkgroup");
 // set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"path1",
 // "lobby"  : "/d/changan/playerhomes/h_none.c",
]));
 // set("no_fight", 1);

  set("item_desc", ([ /* sizeof() == 2 */
  "door" 	: 	(: look_door2, "door" :),
  "bian": "
����������¥��ַ

",
]));
  setup();
}


void init()
{
        add_action("do_push", "push");
	add_action("do_close", "close");
	add_action("do_knock2", "knock");
}

void close_door2()
{
        object room;

        if(( room = find_object(__DIR__"path1")) ) {
                delete("exits/enter");
                        message("vision", "��֨һ��, ���������غ����ˡ�\n",
			this_object());
                room->delete("exits/out");
                message("vision", "��֨һ��, ���Ŵ����������غ����ˡ�\n", room);
        }
        else message("vision","ERROR: door not found(close).\n", room);

}

int do_knock2(string arg)
{
        object mbox;

        if (!arg || arg!="door")
                return notify_fail("��Ҫ��ʲô��\n");

        if (query("exits/enter"))
                return notify_fail("�����ǿ��ŵġ�\n");
	else {
        if( !this_player()->query_temp("mbox_ob") )
		{
       		seteuid(getuid());
        	mbox = new(MAILBOX_OB);
        	mbox->move(this_player());
		message_vision("$N�����������ţ�ֻ�����һ����"
				"һ���ƾɵ����乳ס��$N���½ǣ�����$Nһ����\n",
				this_player());
		}
	else message_vision("$N�����������ţ����ϵ�������˼��Ρ�\n",
				this_player()); 
	return 1;
	}
}

int do_close(string arg)
{
        object room;

        if (!query("exits/enter"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "door" && arg != "enter"))
                return notify_fail("��Ҫ��ʲô��\n");

        remove_call_out("close_door2");
        call_out("close_door2", 2);

        return 1;
}

int do_push(string arg)
{
        object room, mbox;

        if (query("exits/enter"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

        if (!arg || arg!="door")
                return notify_fail("��Ҫ��ʲô��\n");

        if( room = find_object(__DIR__"path1") ) {
                set("exits/enter", __DIR__"path1");
                message_vision("$N������������ţ�ֻ��֨��һ�������������ؿ���һ���졣\n",
                        this_player());
                room->set("exits/out", __FILE__);
                message("vision", "�����������ţ�ֻ��֨��һ�������������ؿ���һ���졣\n",
                        room);
                remove_call_out("close_door2");
                call_out("close_door2", 10);

        }
        else message("vision", "ERROR: door not found(push).\n",this_player());

        return 1;
}

int valid_leave(object me, string dir)
{
        object mbox;

        	if( mbox = me->query_temp("mbox_ob") ) {
               		message_vision("$N������һ�ԭ����\n", me);
                	destruct(mbox);
       		}
 		return 1;
}

string look_door2()
{
	return("һ�����˳���Ľ��š����Ϲ���һ���ƾɵ����䡣\n"
		"�������������ţ������������ơ�\n");
}
