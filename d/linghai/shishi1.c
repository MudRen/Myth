//by dewbaby
//shishi1 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", YEL"����ʯ��"NOR); 
         set ("long", @LONG 
        
����һ�䷽�ε�Сʯ�ҡ�ǽ���ϰ߲߰����ģ�����
˿˿ģ�������Ѫ�����������￴��һ�ᣬ�Ͳ���
�ٶ������СС��ʯ�����ƺ�������ʲô����...
LONG); 
        
         
        set("exits", ([ /* sizeof() == 1 */

        "east":__DIR__"hudi2",        
        ])); 

        setup(); 
        }

