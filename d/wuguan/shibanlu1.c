//Cracked by Roath
// shibanlu1.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "ʯ��·"); 
	set("long",@LONG
����һ���Ѿ������ߵù��������ʯ��·��·���೤����
��ݡ���������ݴ�Ժ�����������ݵ��ʷ��ˡ�
LONG);
	
	set("exits",([
		"west" : __DIR__"dayuan",
		"east" : __DIR__"shibanlu3",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
