//Cracked by Roath
// xiaojing4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С��"); 
	set("long",@LONG
������һ��С���ϡ����Զ������֣�������һ������Ϣ��
��ͤ�������ǹ��߷���������һ��ʯ��·�� 
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing2",
		"south" : __DIR__"shibanlu6",
		"west" : __DIR__"gongjufang",
		])); 
	
	set("no_fight",1);
	
	setup(); 
} 
