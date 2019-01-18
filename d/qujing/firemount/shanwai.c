// created by snowcat on 4/11/1997
// room: shanwai

inherit ROOM;
inherit "/std/dird.c";
int check_move(object me, string arg);

void create ()
{
  set ("short", "ɽ��С·");
  set ("long", @LONG

��ͻȻ���˻���ɽ�������棬�������Ǻ�ͨͨ�Ļ���ɽ����������
��һ��ǿ�ҵĺ�ζ���ȵ������������ܡ�������һ��С����ͨ��ɽ
����������

LONG);

  set("exits", ([
        "northdown"  : __DIR__"hongyan",
        "southeast"  : __DIR__"huoyan",
     ]));
  set("outdoors", "firemount");

  setup();
}

void init()
{
add_action("do_look", "look");
}

int do_look(string arg)
{
if (arg=="southeast") {
	if (this_player()->query("obstacle/firemount")=="done")
		set("exits/southeast", __DIR__"nofire");
	else set("exits/southeast", __DIR__"huoyan");
	}
return this_player()->force_me("look "+arg);
}

int valid_leave(object me, string dir)
{
  if ( dir=="southeast" ) {
	if (me->query("obstacle/firemount")!="done") {
		set("exits/southeast", __DIR__"huoyan");
		me->set_temp("burnt_in_mount",0);
		me->set_temp("fanned_in_mount",0);
		me->set_temp("fan_times_in_mount",0);
		}
	else {
		set("exits/southeast", __DIR__"nofire");
		}
	return check_move(me, dir);
	// mon 4/11/98 modified this to prevent Illegal move error.
	}
return ::valid_leave(me, dir);
}


int check_move(object me, string arg)
{
	string dest, mout, min, dir;
	object env, obj;
	mapping exit;

	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

	if( me->query_temp("no_move") )
		return notify_fail("�㱻��ס�ˣ����ﶯ���ˣ�\n");

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}

	dest = exit[arg];
	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("�޷��ƶ���\n");

	dir = cdir(arg);

	if( me->is_fighting() ) {
		mout = "��" + dir + "��Ķ����ˡ�\n";
		min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	} else {
		mout = "��" + dir + "�뿪��\n";
		min = "���˹�����\n";
	}

	if( !wizardp(me) || !me->query("env/invisibility") )
		message( "vision", me->name() + mout, environment(me), ({me}) );
	if( me->move(obj,1) ) {
	    // move silently so only see room once.
	    // mon 4/11/98
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") )
			message( "vision", me->name() + min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}


