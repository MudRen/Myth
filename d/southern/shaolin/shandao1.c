
inherit ROOM;

void create ()
{
	set ("short", "ɽ��");
	set ("long", @LONG

����ɽɽ���Ķ���ɽ��ȴ��һ���п���ʯ������ģ��ΰ��������ʵ��С��
�����Ƴ�����Ϊ���������¶����䣬�������
LONG);


	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"shanjiao",
		"southup" : __DIR__"shandao2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
               __DIR__"npc/yunyouseng" : 1,
	]));


        set("outdoors", 1);

	setup();
}


