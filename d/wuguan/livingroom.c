//Cracked by Roath
// livingroom.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "����"); 
	set("long",@LONG
����߽����������ң�һ�ɵ��������������������㾫
��Ϊ֮һ����Ѳ����ȥ��ԭ��������˿������ȼ�ŵļ����㡣
LONG);

	set("exits",([
		"north" : __DIR__"houyuan",
		])); 
	set("no_fight",1);

	setup(); 
} 
