//Cracked by Roath
// wuguangate.c
//written by kittt

#define YANGZHOU			"yangzhou"
#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "������ݴ���"); 
	set("long",@LONG
����һ�����ƺ�����ݣ����������ţ���������һ���
��(bian)�ſڶ׾����������͵�ʯʨ�ӣ�����ﴫ��һ������
�����������˵�������Ѿ����ϰ������ʷ�ˣ�ר������һ
Щ���뽭�������֣�������ѧϰһЩ�������书�Ժ�����߽�
����      
LONG);

	set("exits",([
		"north" : CITY_OB(YANGZHOU,"xidajie2"),
		"south" : __DIR__"qianyuan",
		])); 
	
	set("objects", ([
                __DIR__"npc/menwei" : 1,
		__DIR__"npc/xiaosi" : 1,
		]));
		
	set("item_desc",(["bian":HIY "
	
	
       ##############################
       ####                      ####
       ####      �� �� �� ��     ####
       ####                      ####
       ##############################\n\n" NOR]));
             
        setup(); 
	
} 

int valid_leave(object me, string dir)
{
	if (me->query("combat_exp")>20000 && dir=="south")
		return notify_fail("�������ڵ��书��������Ҫ�ڽ�ȥ�˷��ഺ�ˡ�\n");

	return ::valid_leave(me, dir);
}
