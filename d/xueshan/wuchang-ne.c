//standroom.c used by weiqi...others may hate this format:D
//wuchang-ne.c

inherit ROOM;

void create ()
{
	set ("short", "�����䳡");
	set ("long", @LONG

���Ǳ���ǰ��һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-e",
		//"north" : __DIR__"icegate",
		"west" : __DIR__"wuchang-n",
		//"east" : __DIR__"chufang",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 2,
		//__DIR__"npc/yingwu-guai" : 1,
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

