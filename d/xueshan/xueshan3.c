//standroom.c used by weiqi...others may hate this format:D
//xueshan3.c

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
		"southeast" : __DIR__"xueshan2",
		"north" : __DIR__"snowmaze1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}


