//Cracked by Roath
// zoulang.c
//written by kittt

inherit ROOM; 
int valid_leave;

void create() 
{
	set("short", "����"); 
	set("long",@LONG
��첽����һ��խխ�����ȣ���������ķ����д�������
�������̽ͷһ����һ�һ�˯�ø������Ƶġ�������Ů��Ϣ�ҡ�
����������Ϣ�ҡ�    
LONG);

	set("exits",([
		"north" : __DIR__"xiaojing5",
		"west" : __DIR__"fbedroom",
		"south" : __DIR__"mbedroom",
		])); 
	
	set("no_fight",1);
	
	setup();
}

int valid_leave(object ob, string dir)
{
	if((dir=="west") && (ob->query("gender")!= "Ů��"))
		return notify_fail("���ֲ���Ů���ܵ�Ů��Ϣ�Ҹ�ʲ�ᣬ�뿨�Ͱ���\n");
	if((dir=="south") && (ob->query("gender")!= "����"))
		return notify_fail("������Ҫ�ظ������𵽴����ܡ�\n");
	    	
	return ::valid_leave(ob,dir);
}
