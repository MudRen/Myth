//Cracked by Roath
// changlang2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "����"); 
	set("long",@LONG
��������һ�������У���������ԭ�е�һЩ��̴����Ϊ
ʱ���Ե�ʣ��ѿ������ˡ����ȶ�������ݵ�ǰԺ��  
LONG);
       
      set("exits",([
      "east" : __DIR__"school2",
	"west" : __DIR__"changlang4",
])); 
	set("no_fight",1);

        setup(); 
	
} 
