//Cracked by Roath
// changlang1.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "����"); 
	set("long",@LONG
��������һ�������У���������ԭ�е�һЩ��̴����Ϊ
ʱ���Ե�ʣ��ѿ������ˡ�������������ݵ�ǰԺ��  
LONG);
       
      set("exits",([
      "west" : __DIR__"school2",
	"east" : __DIR__"changlang3",
])); 
                            
	set("no_fight",1);


        setup(); 
	
} 
