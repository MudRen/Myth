//Cracked by Roath
// zhangfang.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "�ʷ�"); 
	set("long",@LONG
��ݹ�Ǯ�ĵط����������ǮׯҲ������������ǽ������
�ĸ��̽���֡��ս����𡱡�һλ�����۾����ʷ�����������
�����̣��ƺ�������ʲ�ᡣ  
LONG);

	set("exits",([
		"north" : __DIR__"shibanlu1",
		]));
	set("objects", ([
		__DIR__"npc/cuiguanshi":1,
	]));
	set("no_fight",1);

    setup(); 
}
