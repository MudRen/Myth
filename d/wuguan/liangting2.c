//Cracked by Roath
// liangting2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "��ͤ"); 
	set("long",@LONG
����һ�����˳�������ͤ��������ʯ��ʯ�ʡ����Ը��Ȳ�
���ᣬ���ܵ���ͤ����˸�С�������һ�����ȡ�  
LONG);

	set("exits",([
		"east" : __DIR__"changlang4",
		"south" : __DIR__"xiaojing2",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
