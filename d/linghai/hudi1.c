//by dewbaby

//hudi1   
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIG"��������"NOR); 
         set ("long", @LONG 
        
����һƬ�ľ������̵ĺ�ˮ��������ֱ۽����������
��ȥ���㱻���׵İ���֮��������������˰�������
��Σ��!
LONG); 
        
        set("exits", ([ /* sizeof() == 1 */ 
        "up" : __DIR__"minghu4",       
          "down" : __DIR__"hudi2",       
        ])); 

        setup(); 
        }
    


