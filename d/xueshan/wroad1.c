//standroom.c used by weiqi...others may hate this format:D
//wroad1.c

inherit ROOM;

void create ()
{
	set ("short", "���µ�");
	set ("long", @LONG

������ǰ���ǹ���ȥ�ˡ�������·��һ������Ӷ�������������
��Ŀ�Ĵ���д�ţ������Ƚ��أ��ô�����������
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"xuelu",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "xuesan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

