//Cracked by Roath
// houyuan.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "��Ժ"); 
	set("long",@LONG	
��������ݵĺ�Ժ��Ժ�м䳤��һ�þ޴�Ĳ��ɣ������
�����˾������Ե�ʮ���徻��һ��СѾ�����ڴ�ɨ���ϱ�ͨ��
���������ң������ǿ�����    
LONG);

	set("exits",([
		"north" : __DIR__"keting",
		"south" : __DIR__"livingroom",
		])); 
	set("objects", ([ 
		__DIR__"npc/yahuan" : 1,
		]));
	set("no_clean_up", 0);
	
	setup(); 
} 
