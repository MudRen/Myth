//Cracked by Roath
//huludi.c

inherit ROOM;

void create ()
{
	set ("short", "��«��");
	set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ��������Ǻ�«�ء�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northeast" : __DIR__"xiguadi",
		"south" : __DIR__"luobodi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/hulu" : 2,
	]));

	//create_door("south", "�滨��", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
