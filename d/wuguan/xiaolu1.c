//Cracked by Roath
// xiaolu1.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С·"); 
	set("long",@LONG
����һ���ö���ʯ���ɵ�С·���������������Ǻ������
�������е�����ˮ���еİ��Ŷ�����������һ��ʯ��·�� 
LONG);

	set("exits",([
		"north" : __DIR__"shibanlu5",
		"south" : __DIR__"xiaolu2",
		])); 
	set("objects",([
		__DIR__"npc/guanjia" : 1 
		]));
	
	setup(); 
} 
