//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "˵����");
	set ("long", @LONG

˵����������Ԫ����Ϊ�����µ���˵���۵����衣�Ƚ������Դ�
����һ�ķ�̨��̨�����Ѻ�������Զ�����̨����滷�ơ�����
ǽ�Ϲ���Щɽˮ�ֻ������Ǿ�֮���壬����������
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"epiandian",
		"westup": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
   "/d/obj/misc/baguafu":1,
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
