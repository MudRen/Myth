//Cracked by Roath
// pinchating.c
// written by kittt
// add by yfengf

inherit ROOM; 

#include <ansi.h>

void create() 
{
	set("short", HIG"Ʒ��ͤ"NOR); 
	set("long",@LONG
�㲦����Ҷ��һ��ͤ��ӳ��������ͤ���ϴ��顰Ʒ��ͤ��
�����֡�ͤ������Ϯ�ˣ�ȷΪƷ��ĺõط��������ܿ���һ��
С�š�
LONG);

	set("exits",([
		"north" : __DIR__"huayuan",
		"south" : __DIR__"bridge",
		])); 
	set("no_fight",1);
	set("objects",([
		__DIR__"obj/tea" : 	2,
		__DIR__"npc/xiaohong":	1,	
		]));
	replace_program(ROOM);
	
	setup(); 
} 
