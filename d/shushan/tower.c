//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

inherit ROOM;                                                        
#include <ansi.h>                                                                     

void create ()                                                       
{                                                                    
  set ("short", HIG"������"NOR);                                   
  set ("long", @LONG                                                 
 �������Ƶ���������˵����װ���������֣��Ա���һʯ��(stone)��                                           
LONG);                                                          
        set("item_desc", ([
                "stone": @TEXT
��������������ħ���������������

TEXT        ]) );
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "enter" : __DIR__"entrance",                                                                              
  "south" : __DIR__"bamboo",
                                     
]));

set("objects",([
        __DIR__"npc/lxy" : 1,
        __DIR__"npc/linyueru" : 1,
    ]));                                                                 
     set("outdoors", "shushan");                                                                  
  setup();                                                           
}
