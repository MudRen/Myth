//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "�Ӹ�");
	set ("long", @LONG

�Ӹ�����һ�ķ�С�ң�����һ�ھ��֣�����ռ�������ڵĿռ䣬
����Χ�г����϶�˿�ͨ����������С��ͨ�������С������ı�
��ף��˳���Ⱦ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"eastway3",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
