//standroom.c used by weiqi...others may hate this format:D
//xueshan6.c

inherit ROOM;

void create ()
{
	set ("short", "ããѩ��");
	set ("long", @LONG

�����Х����ѩãã�����治Զһ���޴�ı�����ᶫ�������
��������ߡ����֮��������Լ��ƺ����ޱ��������
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xueshan5",
		"north" : __DIR__"bingchuan",
		//"west" : __DIR__"xihai",
		//"east" : __DIR__"eroad1",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}



