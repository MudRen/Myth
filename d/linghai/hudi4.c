//by dewbaby
//hudi4
  
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
        
         
         set("exits", ([ /* sizeof() == 4 */ 
         "up" : __DIR__"hudi3",
        "down": __DIR__"huxin",
        "east":__DIR__"xiaolu",       
         "west":__DIR__"xiaolu1",       
        ])); 

        setup(); 
        }
  

