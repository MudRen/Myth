//Cracked by Roath
// kitchen.c

//written by kittt



// By yfengf



#include <ansi.h>



inherit ROOM; 



void init();

int do_sheng(string arg);

int over_sheng(object me);



void create() 

{

        set("short", "����"); 

        set("long",@LONG

������ݵĳ�����ŨŨ������Ǻ����û��������ֻ����һ

λ������æ����ͣ��һ�᳴��һ���С��������һ�ߣ��и�¯

���Ѿ�Ϩ���ˡ��������ò͵ĵط���   

LONG);

       

        set("exits",([

                "north" : __DIR__"dinningroom",

                ])); 

        set("objects", ([

                __DIR__"npc/wangchuzi":1,

        ]));

        set("no_fight",1);

        set("no_clean_up", 0);

      

  setup(); 

        

} 



void init()

{

        add_action("do_sheng","sheng");

}



int do_sheng(string arg)

{

	object ob=this_player();

	

	return JOB_OB("wuguan")->job_shenghuo(ob,arg);

}

                

