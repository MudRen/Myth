//Cracked by Roath
// shibanlu4.c
// written by kittt

inherit ROOM;

void create() 
{
	set("short", "ʯ��·"); 
	set("long",@LONG
����һ���Ѿ������ߵù��������ʯ��·����һ��С�Ĳ�
�Ͽ���̦��ˤ�˸�����ſ���������䳡��ʱ�����ٺٵ�������
�����̲�סҪȥ������
LONG);
	
	set("exits",([
		"north" : __DIR__"lianwuch1",
		"west" : __DIR__"shibanlu1",
		"east" : __DIR__"shibanlu5",
		])); 
	set("no_fight",1);

	setup(); 
} 
