//by dewbaby
//hudi3 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIG"��"GRN"��"HIG"��"GRN"��"NOR); 
         set ("long", @LONG 
        
����һƬ�ľ�������������ɫ����ˮ����ӿ��������ȥ
����������ȴ��ʮ�ֲ�ȷ��.....

���������˹�������ʱע��������Ƿ��п�������
��˵�Ÿ����������͵�ˮ�ֳ��֣������˱��е�ʬ�ǲ�ȫ��
LONG); 
        
         
        set("exits", ([ /* sizeof() == 3 */ 
        "up" : __DIR__"hudi2",
         "down":__DIR__"hudi4",
         "east":__DIR__"shishi2",       
        ])); 

        setup(); 
        }
  

