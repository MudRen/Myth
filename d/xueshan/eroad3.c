//standroom.c used by weiqi...others may hate this format:D
//eroad3.c

inherit ROOM;

void create ()
{
	set ("short", "���µ�");
	set ("long", @LONG

���µ׵ĹսǴ������α����ڴ˽��ᣬ���Ͽ�ȥ���Ʋ�����ô
�վ��ˡ�
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
//		"north" : __DIR__"chufang",
		"west" : __DIR__"eroad2",
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

	if( !arg || arg != "up" ){
		return notify_fail("��Ҫ��������ȥ��\n");
	}
	message_vision("$N���㲢�ã���ס�����������˹�ȥ��\n", me);
	me->move(__DIR__"bingya-up1");
	message_vision("$N���������ش��������˹�����\n", me);   
	return 1;    
}


