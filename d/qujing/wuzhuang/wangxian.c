//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "����̨");
	set ("long", @LONG

����̨����������ʯ�̾ͣ������������̫��֮�⡣̨�з�
һ�߸�ͭ¯��¯��С���е������̡�̨���г߸߻������Ե�����
�Զ��ɽ�£�����ɽ�����ޣ�ˮ������������г���֮�⡣
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"westway1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/lancaihe" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
