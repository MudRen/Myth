//Cracked by Roath
// xiaolu3.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С·"); 
	set("long",@LONG
����һ���ö���ʯ���ɵ�С·���������������Ǻ������
�������е�����ˮ���еİ��Ŷ�����������һ���񷿣�������
��𱧽������� 
LONG);
	
	set("exits",([
		"north" : __DIR__"xiaolu2",
		"south" : __DIR__"xiaolu4",
		"east" : __DIR__"chaifang",
		])); 
	
	set("no_fight",1);

    setup(); 
} 
