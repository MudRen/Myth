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
        "up" : __DIR__"saveling",                                      
        "southeast" : __DIR__"hole2",
]));                                                                                                                          
    set("objects",([
        __DIR__"npc/dragon1" : 1,
    ]));    
  setup();                                                           
}

int valid_leave(object me, string dir)
{

   if (dir == "southeast" ) {
        if (objectp(present("dragon", environment(me))))
   return notify_fail("���ǰ�����ɱ���ѣ���\n");
        }   
        return ::valid_leave(me, dir);
}
                                 
