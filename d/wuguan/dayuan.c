//Cracked by Roath
// dayuan.c
//written by kittt

#include <ansi.h>

inherit ROOM; 

int do_sao(string arg);
int del_busy(object me);
void init();

void create() 
{
	set("short", "��ݴ�Ժ"); 
	set("long",@LONG
����Ƕ�����ݵĴ�Ժ�����������Ĵ��Ǻ������
�����ꡣ���Ҵҵز�֪����æЩʲ�ᡣ��������ݵ�ǰԺ����
�����������ȡ�����ͨ������Ŀ�����  
LONG);
       
	set("exits",([
		"north" : __DIR__"qianting",
		"southup" : __DIR__"keting",
  		"east" : __DIR__"shibanlu1",
    	"west" : __DIR__"shibanlu2",
	])); 
	set("no_fight",1);
    
	setup(); 
	
} 

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_saodayuan(ob,arg);
	
}

int valid_leave(object ob, string dir)
{
	if(!JOB_OB("wuguan")->wrong_way(ob,"dayuan",dir))
		return notify_fail("�����Ȼ�ȥ��Ҫ����ɡ�\n");
	
	return ::valid_leave(ob, dir);
}
