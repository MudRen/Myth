//standroom.c used by weiqi...others may hate this format:D
//binggukou.c

inherit ROOM;

void create ()
{
	set ("short", "���ȿ�");
	set ("long", @LONG

����ͻȻ������һ����ȡ�����ֻ�ܿ���һ�ε��������Ƶı�
�£�����������ѩ�����ƣ�ʲôҲ�������ˡ����ʹȵ��ƺ���
һ�ɴ��̵���ζƮ���������ڱ���ѩ���������������㲻����
����Ȼ�Ķ���
LONG);

	set("item_desc", (["north" : "������ѩ�����ƣ�ʲôҲ�����塣\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"bingchuan",
		"north" : __DIR__"bingya-up7",
		"west" : __DIR__"bingchuan",
		"east" : __DIR__"bingchuan",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 1,
	]));


	set("outdoors", "xuesan");

	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();

	if( !arg || arg != "down" ){
		return notify_fail("��Ҫ��������ȥ��\n");
	}
	message_vision("$N���㲢�ã���ס�����������˹�ȥ��\n", me);
	me->move(__DIR__"bingya-up7");
	message_vision("$N���������ش��������˹�����\n", me);   
	return 1;    
}

int valid_leave(object me, string dir)
{
	if (dir == "north" )
	{
		message_vision("$N����һ�е���������һ��������\n", me);
		message("vision", "���ã�һ��ɱ���ĲҺŴӱ����´���������\n", environment(me), ({ me }));

		call_out("do_unconcious", 0, me);
		return notify_fail("���ˣ�����\n");
	}

	return ::valid_leave(me, dir);
}

void do_unconcious(object me)
{
		me->move(__DIR__"binggu");
		message_vision("ֻ��һ���ҽУ�$N�����شӱ�����ˤ��������\n", me);
	me->unconcious();
}
