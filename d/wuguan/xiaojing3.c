//Cracked by Roath
// xiaojing3.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С��"); 
	set("long",@LONG
������һ��С���ϡ����Զ������֣�������һ������Ϣ��
��ͤ�����߾���ݵı�������������һ��ʯ��·��
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing1",
		"south" : __DIR__"shibanlu5",
		"east" : __DIR__"bingqifang",
		]));
	
 	set("no_fight",1);
 	
 	setup(); 
} 
