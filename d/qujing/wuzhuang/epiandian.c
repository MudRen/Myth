//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "��ƫ��");
	set ("long", @LONG

��ƫ����Ҫ�Ǵ��ͷ��֮�á����ڰ��ż���̴ľ�Ρ�ľ��֮�Ϲ�
�˼����ֻ�������һ�����飺�����������٣��ž�����������д
��������ǳ������Ԭ���
LONG);

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"eastway2",
		"west" : __DIR__"zhengdian",
		"north" : __DIR__"shuofa",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/mingyue" : 1,
	]));

create_door("east", "��ľ��", "west", DOOR_CLOSED);
	//set("outdoors", "wuzhuang");

	setup();
}
