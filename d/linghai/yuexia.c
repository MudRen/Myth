//by dewbaby
//yuexia 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short",BLINK+HIB"����ͤ"NOR); 
         set ("long", @LONG 

                **
                **
              ******
            ***********
         *****************
       *********************
     **************************
************---����ͤ---***********
����������������������������������������
---   ���µ�����  ��������ʱ��?  ---  
   *        **********          *
   Y        *        *          Y
   Y        **********          Y
   Y        *        *          Y
   Y        **********          Y
   Y        *        *          Y
   Y        *        *          Y
   Y       d       q *          Y
   Y      d          d          Y
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
 ---------------------------------
<<-------------------------------->>
   -----------------------------
LONG); 
        
         
              set("exits", ([ /* sizeof() == 3 */  
        "west":__DIR__"shulin1",        
          "east":__DIR__"cave1",
         "north":__DIR__"kezhan",
        ])); 

        setup(); 
        }



