//Cracked by Roath

//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIM"������"NOR);                                   
  set ("long", @LONG                                                 
һ�����������������ǰ�������Ա�һ��������                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
        "northeast" : __DIR__"hole3",                                      
        "west" : __DIR__"hole5",
]));                                                                                                                          
    set("objects",([
        __DIR__"npc/dragon4" : 1,
    ]));    
  setup();                                                           
}

int valid_leave(object me, string dir)
{

   if (dir == "west" ) {
        if (objectp(present("dragon", environment(me))))
   return notify_fail("���ǰ�����ɱ���ѣ���\n");
        }   
        return ::valid_leave(me, dir);
}
