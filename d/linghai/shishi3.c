//by dewbaby
//shishi3
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIW"����"NOR); 
         set ("long", @LONG 
        
���ﾲ���ĵģ����������ˡ������ؿ��˿�
���ܣ��������ֱ���һ��Сʯ�š�
LONG); 
        
         
        set("exits", ([ /* sizeof==1  */
        "east":__DIR__"house1",        
        ])); 

        setup(); 
       }
