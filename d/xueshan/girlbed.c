//standroom.c used by weiqi...others may hate this format:D
//girlbed.c

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

���ϣ�˯���ĵط���
LONG);

	//set("item_desc", (["bed" : "һ�ž��µĴ���(gosleep, gobed, bed)��\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"binggu",
		//"north" : __DIR__"restroom",
		//"west" : __DIR__"restroom",
		//"east" : __DIR__"chufang",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
		"out" : __DIR__"girlroom",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 2,
		//__DIR__"npc/yingwu-guai" : 1,
	]));

	set("sleep_room",1);
	set("if_bed",1);

	//set("outdoors", "xueshan");

	setup();
}


