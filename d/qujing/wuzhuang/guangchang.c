//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "��ǰ�㳡");
	set ("long", @LONG

�����Ǳ���֮ǰ��һ���㳡���Ӵ��ݿ���������ۻ룬���Ʋ�
�ס������и����������Ƶĸ������ϵĴ�������̫��֮�Σ���
���ο�������������������̵ľ����ķ���ʯ�����Ͽɿ���ɽ��
ǰ��������������С��ͨ����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"linkway",
		"enter" : __DIR__"zhengdian",
		"east" : __DIR__"eastway1",
		"west" : __DIR__"westway1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/tieguaili" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
