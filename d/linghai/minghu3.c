//by dewbaby

//minghu3
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIC"��������"NOR); 
         set ("long", @LONG 
        
�����Ǵ������ϣ����ϴ���������ȶ��ˡ����б�
���������ɻ��ƽ���ˮ��С�����ɣ��������С�������
¥̨ͤ����������䡣��ֱ����ʤ�ա�
LONG); 
       
        set("outdoors", 2); 
        set("exits", ([ /* sizeof() == 2 */ 
        "north" : __DIR__"minghu4", 
         "south" : __DIR__"minghu2",      
        ])); 
       
        setup(); 
      }
 

