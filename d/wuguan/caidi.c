//Cracked by Roath
// caidi.c

//written by kittt



#include <ansi.h>



inherit ROOM; 



int do_chu(string arg);

int do_jiao(string arg);

void init();



void create() 

{

	set("short", "�˵�"); 

	set("long",@LONG

����һ������Լ������ֲ˵ĵط���������������ܲ���

�ײ˸�ɫ��ȫ�������Χ�˲�ע�⣬���˸��عϴ��������        

LONG);

       

      set("exits",([

 	"north" : __DIR__"xiaolu4",

])); 

	

	set("no_fight",1);



        setup(); 

	

} 



void init()

{

	add_action("do_chu","chu");

	add_action("do_jiao","jiao");

}



int do_chu(string arg)

{

	object ob=this_player();

	

	return JOB_OB("wuguan")->job_chucao(ob,arg);

}



int do_jiao(string arg)

{

	object ob=this_player();

	

	return JOB_OB("wuguan")->job_jiaoshui(ob,arg);

}

