//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

������ׯ�۵���������š������м���ľ�������������°�
�ĵ񻨸��ӡ��������п��ڹ������װ�ɵġ���ء����֣�����
һ����������㼸��������һ���ƽ�¯ƿ��¯�߰��ż����㡣
���������һ��ƫ�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"out" : __DIR__"guangchang",
		"east" : __DIR__"epiandian",
		"west" : __DIR__"wpiandian",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/caoguojiu" : 1,
	]));

	set("valid_startroom", 1);
//	set("outdoors", "wuzhuang");

	setup();
}

