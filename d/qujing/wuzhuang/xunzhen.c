//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "Ѱ��̨");
	set ("long", @LONG

Ѱ��̨����������ʯ�̾ͣ������������̫��֮�⡣̨�з�
һ�߸�ͭ¯��¯��С���е������̡�̨���г߸߻������Ե�����
�Զ��ɽ�£�����ɽ�����ޣ�ˮ������������г���֮�⡣
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"eastway1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/hanxiangzi" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
