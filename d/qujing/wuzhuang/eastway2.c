//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "��С��");
	set ("long", @LONG

���Ǵ����һ�����ȣ���������Ժ��С������ľ���̵أ�
��ɨ�ļ�Ϊ�ɾ����������淢��֨֨�����������������ľ����
����һЩɽˮ�������һ��ľ��ͨ����ƫ�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"eastway1",
		"north" : __DIR__"eastway3",
		"west" : __DIR__"epiandian",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

create_door("west", "��ľ��", "east", DOOR_CLOSED);
//	set("outdoors", "wuzhuang");

	setup();
}
