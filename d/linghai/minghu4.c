//by dewbaby

//minghu4   
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIC"��������"NOR); 
         set ("long", @LONG 
        
�����Ǵ������ϣ����ϴ���������ȶ��ˡ����б�
���������ɻ��ƽ���ˮ��С�����ɣ��������С�������
¥̨ͤ����������䡣��ֱ����ʤ�ա���ʱ����������
�洫���������������ƺ��Ǹ�С���̡�
LONG); 
       
        set("outdoors", 2); 
        set("exits", ([ /* sizeof() == 2 */ 
        "north" : __DIR__"minghu5", 
         "south" : __DIR__"minghu3",
         "west"  : __DIR__"xdian",      
        ])); 
       
        setup(); 
      }


      void init() 
      { 
          add_action("do_dive", "dive"); 
      } 
      int do_dive() 
      {   object me,ridee; 
          me=this_player(); 
          ridee=me->ride(); 
                   if( (!present("bishui zhou", me))&& 
                   (!((string)me->query("family/family_name")=="��������")) ) 
                   return 
      notify_fail(HIY"��һ����������ˮ��......\n\n"HIW"��û����þͱ���ð�����ֻ�øϽ����ϰ�����\n"NOR); 
       
                 if (ridee && ridee->query("under_water")) {  
                   message_vision("$Nһ��$n��ͷ�����˴���Ծ��ˮ�С�\n",me,ridee);  
                   ridee->move(__DIR__"hudi2");  
      } 
       else 
           message_vision("$N���黶�죬һ����������ˮ�У�Ȼ�󲻼��ˡ�\n", me); 
            me->move(__DIR__"hudi1"); 
           message_vision("$N���˹����� \n", me); 
           return 1; 
      } 
 



 

