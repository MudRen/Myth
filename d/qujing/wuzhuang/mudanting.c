//Cracked by Roath
//mudanting.c
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "ĵ��ͤ");
	set ("long", @LONG

      ***********************
      &      ĵ��ͤ         &
      ***********************         

��Ȼ��������԰�ľ���ȥ���������������������󣬴��������
�����ֿɼ�������ľ�԰�з���񳪣�ʱ�м�Ƭ��Ƶľհ����
Ʈ����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"juyuan",
		"north" : __DIR__"southpool",
		"down" : __DIR__"anshi",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/misc/table" : 1,
		__DIR__"npc/hanzhongli" : 1,
	]));

	create_door("down","���װ���", "up", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
