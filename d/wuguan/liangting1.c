//Cracked by Roath
// liangting1.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "��ͤ"); 
	set("long",@LONG
����һ�����˳�������ͤ��������ʯ��ʯ�ʡ����Ը��Ȳ�
���ᣬ���ܵ���ͤ����˸�С�������һ�����ȡ� 
LONG);

	set("exits",([
		"west" : __DIR__"changlang3",
		"south" : __DIR__"xiaojing1",
		])); 
	set("no_fight",1);

	setup(); 
} 
