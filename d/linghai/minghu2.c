//by dewbaby

//minghu2
  
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
        "north" : __DIR__"minghu3", 
         "south" : __DIR__"minghu1",      
        ])); 
       
        setup(); 
      }
 

