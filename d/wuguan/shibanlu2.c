//Cracked by Roath
// shibanlu2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "ʯ��·"); 
	set("long",@LONG
����һ���Ѿ������ߵù��������ʯ��·��·���೤����
��ݡ����������ݵĴ�Ժ�ˣ�����������Լ����ѧ�á�
LONG);
	
	set("exits",([
//             "south" : __DIR__"xuetang",
		"east" : __DIR__"dayuan",
		"west" : __DIR__"shibanlu4",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
