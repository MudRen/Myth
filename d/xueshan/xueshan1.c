//standroom.c used by weiqi...others may hate this format:D
//xueshan2.c

inherit ROOM;

void create ()
{
	set ("short", "ããѩ��");
	set ("long", @LONG

�����Х����ѩãã��������ȥ�������Ӳ�����ѩ�塣���֮��
���Ѻ�������������ѩ����ѩ��
LONG);


	set("exits", 
	([ //sizeof() == 4
		"south" : "/d/moon/kunlun",
		"north" : __DIR__"xueshan2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}


