//Cracked by Roath
// changlang4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "����"); 
	set("long",@LONG
��������һ�������У���������ԭ�е�һЩ��̴����Ϊ
ʱ���Ե�ʣ��ѿ������ˡ�������һ����ͤ��  
LONG);
       
      set("exits",([
      "east" : __DIR__"changlang2",
	"west" : __DIR__"liangting2",
])); 
	set("no_fight",1);


        setup(); 
	
} 
