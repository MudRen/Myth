//Cracked by Roath
//fabao-road1.c
inherit ROOM;

void create ()
{
	set ("short", "��ʯ·");
	set ("long", @LONG

бб��һ��ɽ�����������ȥ��һ·�ϻ�ѩԽ��Խ���������ι�
״�Ĳ�����ʯȴԽ��Խ�ࡣ���л���һЩ����ɫ�ʰ�쵣���֪��
�Ӻζ�����
LONG);

	set("exits", 
	([ //sizeof() == 4
		//"out" : __DIR__"guangchang",
		"east" : __DIR__"ontop2",
		"west" : __DIR__"fabao-road2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	//set("valid_startroom", 1);
	set("outdoors", "moon");

	setup();
}

