// Room: /d/wiz/courthouse.c

#include <ansi.h>
inherit ROOM;

//seems should block chat and rumor here:)
//and can't quit here...hehe:)...weiqi
int do_chat();
int do_rumor();
int do_quit();

void create()
{
	set("short", "��Ժ");
	set("long", @LONG

���������ʻ����˵ķ�Ժ����һ���Ǳ��˼�ٻ�����Ϊ̫������ˣ���
��������������𲻳����йٵ��������⣬�ᱻ���ϼǺţ�������
�ε��˽��ᱻ���Լ��̣��úûش�ɡ�

LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}

void init()
{
	add_action("do_chat", "chat");
	add_action("do_chat", "chat*");
	add_action("do_rumor", "rumor");
	add_action("do_rumor", "rumor*");
	add_action("do_quit","quit");
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("��Ȼһ��������ס��$N��\n", me);
	me->move(this_object());
}

int do_chat()
{
	object me;
	me=this_player();
	write("��������ʵʵ�ش�����ɡ�\n");
	return 1;
}

int do_rumor()
{
	object me;
	me=this_player();
	write("�󵨣��������ﻹ��ɢ��ҥ�ԡ�\n");
	return 1;
}

int do_quit()
{
	object me;
	me=this_player();
	write("�ٺ٣����ܣ��ش���������ͷ����㡣\n");
	return 1;
}

