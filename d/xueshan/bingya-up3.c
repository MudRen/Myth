//standroom.c used by weiqi...others may hate this format:D
//bingya-up3.c

inherit ROOM;

string direction_name(string);
string direction_rev(string);

void create ()
{
	set ("short", "������");
	set ("long", @LONG

��ſ�ڱ����ϣ�������С������
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
		//"north" : __DIR__"chufang",
		//"west" : __DIR__"eroad2",
		//"east" : __DIR__"eroad3",
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

	if( !arg || (arg != "up" && arg != "down" && arg != "left" && arg != "right") )
	{
		return notify_fail("��Ҫ��������ȥ��\n");
	}

	if( arg == "down" ) 
	{
		message_vision("$N���㲢�ã�С���������"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move(__DIR__"bingya-up2");
	}
	else if( arg == "up" ) 
	{
		message_vision("$N���㲢�ã�С���������"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move(__DIR__"bingya-up4");
	} 
	else return notify_fail( "��"+direction_name(arg)+"�Ѿ�û������֮���ˡ�\n" );

	message_vision("$N��"+direction_rev(arg)+"�����˹��������������˿�����\n", me);   
	return 1;    
}

string direction_name(string arg)
{
	if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "right" ) return "��";
	else return "��֪���Ķ�";
}

string direction_rev(string arg)
{
	if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "right" ) return "��";
	else return "��֪���Ķ�";
}



