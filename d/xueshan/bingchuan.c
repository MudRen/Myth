//standroom.c used by weiqi...others may hate this format:D
//bingchuan.c

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

�����˱�������ž���������������ְθ���һ�㡣������ȥ��
һ�������಻����ѩ�壬����ʱ����������Ľ��¡�һ���Ǻ�
������ı�ԭ������еĲ���һ������������ǰ����������
��ı���Ҳ�ڱ�ԭ�д��У���ɲ�صȴ���ʧ������ˡ�
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xueshan6",
		"north" : __DIR__"binggukou",
		"west" : __DIR__"bingchuan",
		"east" : __DIR__"bingchuan",
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



