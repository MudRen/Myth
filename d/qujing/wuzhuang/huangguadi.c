//Cracked by Roath
//huangguadi.c

inherit ROOM;

void create ()
{
	set ("short", "�ƹϵ�");
	set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ��������ǻƹϵء�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"northpool",
		"northeast" : __DIR__"qiezidi",
		"northwest" : __DIR__"luobodi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/dhg" : 3,
	]));

	//create_door("south", "�滨��", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
