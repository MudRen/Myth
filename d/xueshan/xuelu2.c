//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩ·");
	set ("long", @LONG

ǰ���·����ȫ�����������ѩ֮�У�ѩ�µ�һ�����ˣ�
����ﻬ����·������춱��ϣ�����̤һ���գ��Ʊص�
����������е��÷�����ǡ�
LONG);


	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"xuelu1",
		"northup" : __DIR__"xuelu",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}



