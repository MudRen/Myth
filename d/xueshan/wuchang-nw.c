//standroom.c used by weiqi...others may hate this format:D
//wuchang-nw.c

inherit ROOM;

void create ()
{
	set ("short", "�����䳡");
	set ("long", @LONG

���Ǳ���ǰ��һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹��򡣶����һ�����Ӷ���һ�ɴ���ȽȽ��������ǳ�
���ˡ�
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-w",
		//"north" : __DIR__"icegate",
		//"west" : __DIR__"restroom",
		"east" : __DIR__"wuchang-n",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/ice" : 2,
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

