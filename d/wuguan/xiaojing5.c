//Cracked by Roath
// xiaojing5.c

//written by kittt



#include <ansi.h>



inherit ROOM; 



void create() 

{

	set("short", "С��"); 

	set("long",@LONG

������һ��С���ϡ����Զ������֣���������ֺ�����

·���߽�ȥ��������ͨ����Ϣ�ҵĳ��ȡ� 

LONG);



	set("exits",([

		"north" : __DIR__"shibanlu6",

		"south" : __DIR__"zoulang",

		"west" : __DIR__"zhulin",

		])); 

	set("no_fight",1);

	

	setup(); 

}



int valid_leave(object ob, string dir)

{

	if(!JOB_OB("wuguan")->wrong_way(ob,"xiaojing5",dir))

		return notify_fail("�����Ȼ�ȥ��Ҫ����ɡ�\n");

	

	return ::valid_leave(ob, dir);

}
