//Cracked by Roath
// bridge.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "С��"); 
	set("long",@LONG
��������һ������Ϫ���ϵ�С�ţ�Ϫˮ�峺͸�����ճ���
�Ľ��ݡ�С�������ϵ���Ÿ�ʽ�����������Ҳ���������ˡ�
������������Լ�ɼ�һС�ݣ�������Ʒ��ͤ��  
LONG);
       
      set("exits",([
      "south" : __DIR__"yinluju",
	"north" : __DIR__"pinchating",
])); 
	set("no_fight",1);


        setup(); 
	
} 
