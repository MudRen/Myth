//by dewbaby
//huxin 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", GRN"����԰"NOR); 
         set ("long", @LONG 
        
����������׵�һ��С��԰������Ĺ���
ȫ������԰��ʯ���ϵļ���ҫ�۵����顣
������һ���������ɵ�ʯ���������м�ֻ����
��ɵ���������һ����֪��������ʦ֮�֣�
����ʮ�־�ϸ��
LONG); 
        
         
        set("exits", ([ /* sizeof== 4*/

        "up":__DIR__"hudi4",       
         "down":__DIR__"zoulang",        
         "west":__DIR__"jade2",
         "east":__DIR__"feiyange",
        ])); 

        setup(); 
        }
