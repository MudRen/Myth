//Cracked by Roath
// shibanlu6.c

// written by kittt



#include <ansi.h>



inherit ROOM; 



void create() 

{

	set("short", "ʯ��·"); 

	set("long",@LONG

����һ���Ѿ������ߵù��������ʯ��·�������һ����

���ˤ��һ������������ʱ����˻˻���������������һ��

С���������С·ͨ����Ϣ�ҡ�

LONG);



	set("exits",([

		"north" : __DIR__"xiaojing4",

		"east" : __DIR__"shibanlu4",

		"west" : __DIR__"mafang",

		"south" : __DIR__"xiaojing5", 

		])); 

	set("no_fight",1);

	

	setup(); 

} 



int valid_leave(object ob, string dir)

{

	if(!JOB_OB("wuguan")->wrong_way(ob,"shibanlu6",dir))

		return notify_fail("�����Ȼ�ȥ��Ҫ����ɡ�\n");

	

	return ::valid_leave(ob, dir);

}
