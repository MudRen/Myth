//by dewbaby
//jade2 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIC"�鷿"NOR); 
         set ("long", @LONG 
        
���������������һ���鷿����ϸϸ��ȥ������
���е�������ī�㣬�ƺ���Щ���Ѵ���ڴ˺ܶ�
���ˡ�
LONG); 
        
         
        set("exits", ([ /* sizeof==1 */

        "up":__DIR__"jade2",        
        ])); 

        setup(); 
       }
