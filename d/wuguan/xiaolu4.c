//Cracked by Roath
// xiaolu4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С·"); 
	set("long",@LONG
����һ���ö���ʯ���ɵ�С·���������������Ǻ������
�������е�����ˮ���еİ��Ŷ���������ͨ��һ��˵أ�����
��һ�������� 
LONG);

	set("exits",([
		"north" : __DIR__"xiaolu3",
		"south" : __DIR__"caidi",
		"east" : __DIR__"yutang", 
		])); 
	set("no_fight",1);
	
	setup(); 
} 
