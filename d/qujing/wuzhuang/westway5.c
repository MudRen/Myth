//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "��С��");
	set ("long", @LONG

���Ǵ�������һ�����ȣ���������Ժ��С������ľ���̵أ�
��ɨ�ļ�Ϊ�ɾ����������淢��֨֨�����������������ľ����
����һЩɽˮ��������ǹ��е��ӵ�˯����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"westway4",
		"north" : __DIR__"westway6",
		"east" : __DIR__"sleep",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
