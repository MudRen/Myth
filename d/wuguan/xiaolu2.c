//Cracked by Roath
// xiaolu2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С·"); 
	set("long",@LONG
����һ���ö���ʯ���ɵ�С·���������������Ǻ������
�������е�����ˮ���еİ��Ŷ�����������һ��ˮ���� 
LONG);
	
	set("exits",([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"xiaolu3",
		"east" : __DIR__"shuifang",
		 ])); 
	set("no_fight",1);
	
	setup(); 
} 

int valid_leave(object ob, string dir)
{
	if(present("tong",ob)&&dir=="north")
		return notify_fail("��ô������ˮͰ��Ҳ��͵��\n");
	
	return ::valid_leave(ob, dir);
}
