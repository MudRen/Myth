//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "��ש��");
	set ("long", @LONG

ϸ������ש����ɽ�����򱦵���Ͼ���һɫ��ש���ڷ�������
̫��֮�⣬����֮�󡣵���������һƬ���������ѿ�֮��͸����
���ɺ�һƬ�������������󲻾���
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"secondgate",
		"northup" : __DIR__"guangchang",
//		"east" : __DIR__"song1",
//		"west" : __DIR__"zhu1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
