//standroom.c used by weiqi...others may hate this format:D
//xueshan5.c

inherit ROOM;

void create ()
{
	set ("short", "ããѩ��");
	set ("long", @LONG

���ӵ�ɽ���ڴ��ƺ����ƽ̹�������������ǰ�ѩãã��ֻ�Ǳ�
���Ѳ�����ô��Ű�����Ƶ�Ⱥɽ���������һ��ȱ�ڣ���һ��
ϸ΢��ů�����϶�������Ʈ����
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xueshan4",
		"north" : __DIR__"xueshan6",
		"west" : __DIR__"xihai",
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



