//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "���");
	set ("long", @LONG

������ǿ����ţ�ֻ�ǿտյ�����û��ʲô����������������
��ׯ�۵ĺ�Ժ�ˡ���������һ��С��ͨ������������⣬����
�����������Ǹ���԰��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"houyuan",
		"east" : __DIR__"eastway6",
		"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
