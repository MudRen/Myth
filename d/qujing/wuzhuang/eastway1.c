//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "��С��");
	set ("long", @LONG

���Ǵ����һ�����ȣ���������Ժ��С������ľ���̵أ�
��ɨ�ļ�Ϊ�ɾ����������淢��֨֨�����������������ľ����
����һЩɽˮ���������һ����̨��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southup" : __DIR__"xunzhen",
		"north" : __DIR__"eastway2",
		"west" : __DIR__"guangchang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
