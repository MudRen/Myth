//Cracked by Roath
// chaifang.c

//written by kittt





inherit ROOM; 



int do_pichai(string arg);

void init();



void create() 

{

	set("short", "��"); 

	set("long",@LONG

��������ݵĲ񷿣���ľƬ���ض��ǣ�����һ�����õ�ľ

��ѵ��ϸߡ�����Ҳ�м������ںٺٵ��������š� 

LONG);



	set("exits",([

 		"west" : __DIR__"xiaolu3",

 	]));

 	 

	set("no_fight",1);



    setup(); 

} 



void init()

{

	add_action("do_pichai","pi");

}



int do_pichai(string arg)

{

	object ob=this_player();

	return JOB_OB("wuguan")->job_pichai(ob,arg);

}



