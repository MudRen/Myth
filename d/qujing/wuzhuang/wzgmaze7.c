//Cracked by Roath
//standroom.c used by weiqi...others may hate this format:D
//wgzmaze7.c

//this is a maze with 8 rooms forming a ba-gua. to go out, need go through
//each room exactly once. if any room is entered twice, everything is
//reset and need try again from the beginning.

inherit ROOM;

void init();
void reset_path(object);
int check_out(object);

void create ()
{
	set ("short", "������");
	set ("long", @LONG

����ľ�ż��ھ����ĵĺ������棬�ݺύ���Ե����Ǿ��ɡ���
���˴����ɼ������Ͽ���һ�����֣�
		������
		������
		������

LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"wzgmaze3",
		"northeast" : __DIR__"wzgmaze6",
		"southeast" : __DIR__"wzgmaze8",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}

void init()
{       
	object me=this_player();

	add_action("do_jump", "jump");

	if( me->query_temp("wzgmaze7") == 0 )
	{
		me->set_temp("wzgmaze7", 1);
	}
	else if( me->query_temp("wzgmaze7") == 1 )
	{
		reset_path(me);
	}
	
	if( check_out(me) ) me->move(__DIR__"northpool");
}

void reset_path(object me)
{
	me = this_player();

	if( me->query_temp("wzgmaze1") ) me->delete_temp("wzgmaze1");
	if( me->query_temp("wzgmaze2") ) me->delete_temp("wzgmaze2");
	if( me->query_temp("wzgmaze3") ) me->delete_temp("wzgmaze3");
	if( me->query_temp("wzgmaze4") ) me->delete_temp("wzgmaze4");
	if( me->query_temp("wzgmaze5") ) me->delete_temp("wzgmaze5");
	if( me->query_temp("wzgmaze6") ) me->delete_temp("wzgmaze6");
	if( me->query_temp("wzgmaze7") ) me->delete_temp("wzgmaze7");
	if( me->query_temp("wzgmaze8") ) me->delete_temp("wzgmaze8");
	return;
}

int check_out(object me)
{
	me = this_player();

	if ( me->query_temp("wzgmaze1") != 1 ) return 0;
	if ( me->query_temp("wzgmaze2") != 1 ) return 0;
	if ( me->query_temp("wzgmaze3") != 1 ) return 0;
	if ( me->query_temp("wzgmaze4") != 1 ) return 0;
	if ( me->query_temp("wzgmaze5") != 1 ) return 0;
	if ( me->query_temp("wzgmaze6") != 1 ) return 0;
	if ( me->query_temp("wzgmaze7") != 1 ) return 0;
	if ( me->query_temp("wzgmaze8") != 1 ) return 0;
	if( me->query_temp("wzgmaze1") ) me->delete_temp("wzgmaze1");
	if( me->query_temp("wzgmaze2") ) me->delete_temp("wzgmaze2");
	if( me->query_temp("wzgmaze3") ) me->delete_temp("wzgmaze3");
	if( me->query_temp("wzgmaze4") ) me->delete_temp("wzgmaze4");
	if( me->query_temp("wzgmaze5") ) me->delete_temp("wzgmaze5");
	if( me->query_temp("wzgmaze6") ) me->delete_temp("wzgmaze6");
	if( me->query_temp("wzgmaze7") ) me->delete_temp("wzgmaze7");
	if( me->query_temp("wzgmaze8") ) me->delete_temp("wzgmaze8");
	return 1;
}

int do_jump(string arg)
{       
	object me;
	me=this_player();

	if ( !arg || ((arg != "bridge") ))
		return notify_fail("��Ҫ��������\n");
	else
		message_vision("$N��һ�ᣬ��������ȥ...\n",me);

	me->move(__DIR__"inpool");
	message_vision("ֻ�������̡�һ����$N�����ϵ������У�\n", me);
	return 1;
}
