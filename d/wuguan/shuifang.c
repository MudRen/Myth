//Cracked by Roath
// shuifang.c

// written by kittt



inherit ROOM; 



void init();

int do_dashui(string arg);



void create() 

{

	set("short", "ˮ��"); 

	set("long",@LONG

������ݵ�ˮ��������ʪºº�ģ���������һ�ھ�(well)��

��ǽ����������ˮ�ס��㱾����Ҫ����ȥϴ���裬���ֲ�����

Ӿ��ֻ�����ա� 

LONG);

       

	set("exits",([

	 	"west" : __DIR__"xiaolu2",

		]));

	set("item_desc",([

		"well":		"����һ�ھ�������һ���ƾɵ����������������ˮ(da ˮ)��\n"

		]));

	set("objects",([

		__DIR__"obj/tong":	5,

		]));

	set("no_fight",1);	

	

        setup(); 

	

}



void init()

{

	add_action("do_dashui","da");

}



int do_dashui(string arg)

{

	object		ob=this_player();

	

	return JOB_OB("wuguan")->job_dashui(ob,arg);



}



	

