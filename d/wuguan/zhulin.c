//Cracked by Roath
// zhulin.c

//written by kittt



#include <ansi.h>



inherit ROOM; 



void create() 

{

	set("short", "����"); 

	set("long",@LONG

������һƬ�ľ��������У���������͸����Ҷ����������

ů����ġ��������µ������̲�ס���ܡ���������ԼԼ��ȥ

���� 

LONG);



	set("exits",([

		"west" : __DIR__"huayuan",

		"east" : __DIR__"xiaojing5",

		])); 

		

	setup(); 

} 

