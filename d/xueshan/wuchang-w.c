//standroom.c used by weiqi...others may hate this format:D
//wuchang-w.c

inherit ROOM;

void create ()
{
	set ("short", "���䳡");
	set ("long", @LONG

���Ǳ���ǰ��һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-sw",
		"north" : __DIR__"wuchang-nw",
	//	"west" : __DIR__"restroom",
		"east" : __DIR__"wuchang-c",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 2,
		__DIR__"npc/huangque-shier" : 1,
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

