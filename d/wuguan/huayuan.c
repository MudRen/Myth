//Cracked by Roath
// huayuan.c

// written by kittt



#include <ansi.h>



inherit ROOM; 



void create() 

{

	set("short", "��԰"); 

	set("long",@LONG	  

��������֣�����������һƬ������Դ�������ʻ����õ�

�����ǣ�С����վ��֦ͷ���ظ質���㲻�����������в�Ը

�뿪��������һ����ɽ���ϱ߲�֪ͨ���Ķ���        

LONG);



	set("exits",([

		"north" : __DIR__"jiashan",

		"south" : __DIR__"pinchating",

		"east" : __DIR__"zhulin",

		])); 

	set("no_fight",1);



	setup(); 



} 



int valid_leave(object ob, string dir)

{

	if(!JOB_OB("wuguan")->wrong_way(ob,"huayuan",dir))

		return notify_fail("�����Ȼ�ȥ��Ҫ����ɡ�\n");

	

	return ::valid_leave(ob, dir);

}
