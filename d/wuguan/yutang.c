//Cracked by Roath
// yuetang.c

//written by kittt

//modity by yfengf



#include <ansi.h>



inherit ROOM; 



int do_diaoyu(string arg);



void create() 

{

	set("short", "����"); 

	set("long",@LONG

��������һ�������ߡ���������㲻ͣ�Ĵ�����ȥ������

����̲����Աߺü��������ڴ������㲻�Ҵ��ţ�վ��һ�Ծ�

���ؿ���      

LONG);



	set("exits",([

		"west" : __DIR__"xiaolu4",

		])); 

	set("no_fight",1);

	

	setup(); 

}



void init()

{

	add_action("do_fishing","diao");

} 



int do_fishing(string arg)

{

	object ob=this_player();

	

	return JOB_OB("wuguan")->job_diaoyu(ob,arg);

}
