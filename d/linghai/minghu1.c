// by dewbaby
//minghu1
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIC"��������"NOR); 
         set ("long", @LONG 
        
�����Ǵ������ϣ��㾭��һ��������·;�󣬿�����ǰ����ˮ���ĺ���
���в���һ������֮�С�����ɫ�ĺ�ˮ���ŷ����������絴���š���
�м��������㡣
LONG); 
       
        set("outdoors", 2); 
        set("exits", ([ /* sizeof() == 2 */ 
        "north" : __DIR__"minghu2", 
         "southeast" : __DIR__"wxy1",      
        ])); 
       
        setup(); 
       call_other("/obj/board/minghu_b", "???");  
      }
 

