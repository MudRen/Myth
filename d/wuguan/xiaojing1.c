//Cracked by Roath
// xiaojing1.c
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
		"north" : __DIR__"liangting1",
		"south" : __DIR__"xiaojing3",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
