//Cracked by Roath
// mafang.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "��"); 
	set("long",@LONG
�������ݵ��������˺ü�ʮƥ������Ҳ�м�ƥ����
�Ա߷���һЩ���Ϻͼ�Ͱ��ˮ����������ι��ġ�    
LONG);
       
	set("exits",([
		"east" : __DIR__"shibanlu6",
	])); 
	set("objects",([
		__DIR__"npc/horse":1]));
	set("no_fight",1);
		
	setup();
}
