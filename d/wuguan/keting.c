//Cracked by Roath
// keting.c
//written by kittt

#include <ansi.h>

inherit ROOM;

void init();
int fang_tea(string arg);

void create() 
{
	set("short", "����"); 
	set("long",@LONG
����ǹ��������Ӵ����˵ĵط������ܰڷ��ż���̴��ľ
�����ӣ�ǽ�Ϲҵģ��������˵��ֻ�������������λī�͡���
����һ���鷿�����Ͼ͵���ݵĺ�Ժ�ˡ�
LONG);
       
      set("exits",([
      "northdown" : __DIR__"dayuan",
	"south" : __DIR__"houyuan",
        "east" : __DIR__"schoolbook",
])); 
      set("no_clean_up", 0);
	  set("no_fight",1);
        setup(); 
	
}

void init()
{
	add_action("fang_tea","fang");
}

int fang_tea(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_fangcha(ob,arg);
}
	

