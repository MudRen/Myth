//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "ի��");
	set ("long", @LONG

ի����Ϊ���룬������ի����¯�ϵĴ�����������ڡ��ϱ߰�
��һ��ľ��������ľ�ʣ���λ�������ڽ�ի����ǽ�ļ����Ϸ�
�Ÿ���Ϲ������ǹ����Լ��ֵġ�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"eastway5",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
