//Cracked by Roath
// qianyuan.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "ǰԺ"); 
	set("long",@LONG
����������ݵ�ǰԺ���������ɸɾ����ĺ���ˬ��������
��ݵĴ��š����������ǳ��ȣ�����ͨ����ݵ�ǰ����  
LONG);

	set("exits",([
		"north" : __DIR__"wuguangate",
		"south" : __DIR__"qianting",
		"east" : __DIR__"changlang1",
		"west" : __DIR__"changlang2",
		])); 
	set("objects", ([ 
//                __DIR__"npc/jiading" : 2,
		]));
	set("no_clean_up", 0);
	
	setup(); 
//        call_other("/clone/board/wuguan_b", "???");
} 
