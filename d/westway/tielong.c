inherit ROOM;
#include <ansi.h>

#include <ansi.h>


void create ()
{
  set ("short","������");
  set ("long", @LONG

����������ָ�ֵĸ���Ȧ�ɣ�������ʮ�ֵļ�̡�һ���˿���
�������ӳ�ȥ�ģ�������Ҳ����ȥ���԰⿪(break)����
LONG);

  set("exits", ([
//        "southeast" : __DIR__"yinma",
      ]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/quest/longzhu/npc/tlks" : 1,
        ]));
  setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break()
{
	object me=this_player();
	int i;
	i=(int)me->query("force_factor")*5 + (int)me->query("str");

	if( this_object()->query("open") )
		return notify_fail("�����Ѿ����ˣ���Ѿ��ˡ�\n");

	message_vision("$N���������ˣ�˫��һ�Ͼ�����һ����������\n", me);
	
	if( i > 300)
		tell_room(this_object(), "ֻ�������˷������ǣ��ǡ�������������\n");
	else if( i > 200)
		tell_room(this_object(), "ֻ���������������䡭����\n");
	else if( i > 100)
		tell_room(this_object(), "�����˺��󱻰�����һЩ������\n");
	else
		tell_room(this_object(), "�����˺���û��ʲô����������\n");

	this_object()->add("break", i);
	me->receive_damage("kee", 30);
	me->add("force", -(int)me->query("force_factor"));
	
	if( (int)me->query("force") < 0 ){
		me->set("force", 0);
	}

	if ( (int)this_object()->query("break") > 3000 ){
		tell_room(this_object(),"�����˵ķ�϶�㹻һ�������ȥ�ˡ�\n");
		this_object()->set("open", 1);
		set("long", @LONG

һ�����ò�����������Ť���������ó��Ŀ�϶���ÿ�����һ����
���ȥ��
LONG);
		this_object()->set("exits/out", "/d/westway/lu1");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "out" ) {
		if( !this_object()->query("exits/out"))
			return notify_fail("�������û�г�·��\n");
		message_vision("$N��������������˳�ȥ��\n", me);
		return 1;
        }   
	
}




