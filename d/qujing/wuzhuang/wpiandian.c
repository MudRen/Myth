//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "��ƫ��");
	set ("long", @LONG

��ƫ����Ҫ�����ѷ�һЩ��������ĳ�����Ʒ����ľ������
һ����ͭ����̨�����к�����ȼ���������ߵĵ�ľ�������ȣ�
��Լ�����������еķ��������߾ͻص����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"jiangjing",
		"east" : __DIR__"zhengdian",
		"west" : __DIR__"westway2",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
	]));

create_door("west", "��ľ��", "east", DOOR_CLOSED);

	//set("outdoors", "wuzhuang");

	setup();
}

