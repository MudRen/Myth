//Cracked by Roath
//houyuan.c
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "��Ժ");
	set ("long", @LONG

������Ժ����������Ϊ֮һ�ɡ���һ�����ﻨ�㡣Ժ���䲻��
���ó���һ�����Ĳ��á�����һ��С��������֦��ɣ���ѩ�׵�
�滨��Ȼ����ʢ����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"juyuan",
		"south" : __DIR__"houdian",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	create_door("north", "�滨��", "south", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
