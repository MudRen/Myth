//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "�ĸ�");
	set ("long", @LONG

�ĸ��ڳ��ķ���ľ���ϰ������ģ�����ռ�������ڵĿռ䣬��
��Χ�г����϶�˿�ͨ����������С��ͨ������֮�С������ı�
��ף��˳���Ⱦ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"westway3",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
