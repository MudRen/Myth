//Cracked by Roath
// gongjufang.c
// written by kittt
// add by yfeng

inherit ROOM; 

void create() 
{
	set("short", "���߷�"); 
	set("long",@LONG
��������ݵĹ��߷��������õ��˺ܶ࣬������ȥ����
���Թ��߰ڷŵ����ض��ǡ���һ��С�Ĳ��ϰѳ�ͷ����������
�ô���ͷ�ϣ�ʹ����ֱ���������衣    
LONG);
       
	set("exits",([
		"east" : __DIR__"xiaojing4",
		]));
	set("objects",([
		__DIR__"npc/sunguanshi":	1]));
	set("no_fight",1);

    setup(); 
} 
