//Cracked by Roath
// shibanlu5.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "ʯ��·"); 
	set("long",@LONG
����һ���Ѿ������ߵù��������ʯ��·�������һ����
���ˤ��һ�������洫��������㣬������һ��С��������ͨ
����ݴ�Ժ��
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing3",
		"west" : __DIR__"shibanlu3",
		"east" : __DIR__"dinningroom",
		"south" : __DIR__"xiaolu1", 
		])); 
	set("no_fight",1);
	
	setup(); 
} 
