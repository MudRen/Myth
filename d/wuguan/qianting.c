//Cracked by Roath
// qianting.c
// written by kittt
// modify by yfengf

#include <ansi.h>

inherit ROOM; 

void create() 
{
	set("short", "ǰ��"); 
	set("long",@LONG
�����ǹ�������ӭ�ӿ��˵�ǰ��������Ķ��ǽ���������
�͵Ĵ����Ʒ��ǽ�ϻ����Ź����Լ���д��һ����(zi)��ƽʱ
û�˵�ʱ���Եþ����õġ����������ݵĴ�Ժ��  
LONG);
       
	set("exits",([
               "north" : __DIR__"school2",
		"south" : __DIR__"dayuan",
	])); 
        set("valid_startroom",1);
	set("item_desc", ([
		"zi" : "�����øվ��Ĵ���д�š�"+HBWHT HIB "������Զ�����������ֺ�" NOR NOR+"����\n" ,
	]));
	set("objects",([__DIR__"npc/zongguan":1]));// ��ʼ�����ܹ�
		set("no_fight",1);

	setup(); 
}
