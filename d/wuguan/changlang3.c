//Cracked by Roath
// changlang3.c
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
      "west" : __DIR__"changlang1",
	"east" : __DIR__"liangting1",
])); 
	set("no_fight",1);

        setup(); 
	
} 
