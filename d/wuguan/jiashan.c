//Cracked by Roath
// jiashan.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "��ɽ"); 
	set("long",@LONG
����������ǰ����һ���޴�ļ�ɽ�����й�״�ġ�������
̦�ܲ���Ұ�ݴ��������������Ҳ���࿴��  
LONG);

	set("exits",([
		"south" : __DIR__"huayuan",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
