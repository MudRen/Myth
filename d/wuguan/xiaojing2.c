//Cracked by Roath
// xiaojing2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С��"); 
	set("long",@LONG
������һ��С���ϡ����Զ������֣�������һ������Ϣ��
��ͤ��
LONG);

	set("exits",([
		"north" : __DIR__"liangting2",
		"south" : __DIR__"xiaojing4",
		])); 
		
	set("no_fight",1);
	
	setup(); 
} 
