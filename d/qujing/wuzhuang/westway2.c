//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "��С��");
	set ("long", @LONG

���Ǵ�������һ�����ȣ���������Ժ��С������ľ���̵أ�
��ɨ�ļ�Ϊ�ɾ����������淢��֨֨�����������������ľ����
����һЩɽˮ���������һ��С��ͨ����ƫ�ꡣ
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"westway1",
		"north" : __DIR__"westway3",
		"east" : __DIR__"wpiandian",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));
create_door("east", "��ľ��", "west", DOOR_CLOSED);


//	set("outdoors", "wuzhuang");

	setup();
}
