//Cracked by Roath
//juyuan.c
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "��԰");
	set ("long", @LONG

�滨����ȴ������԰��������ָ�ɫ�ľջ����涷�ޡ��㲻�ɵ�
�����˽Ų���Ψ��һ����С�ģ������˽������εĻ��ꡣ����һ
ͤ��������Լ�ɼ���ĵ��ͤ�����֡�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northeast" : __DIR__"mudanting",
		"northwest" : __DIR__"shuoyaopu",
		"south" : __DIR__"houyuan",
                "up" : "/d/quest/m_weapon/lianchuishi",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	create_door("south", "�滨��", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
