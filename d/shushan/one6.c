//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "��һ���Թ�");                                   
  set ("long", @LONG                                                 
������ʯ�ڵ��Թ���һ��ŨŨ�����������ڿ����                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"one1",                                         
  "east" : __DIR__"one2",                                    
  "west" : __DIR__"one2",                                       
  "south" : __DIR__"one7",
                                     
]));
    set("objects",([
        __DIR__"npc/yao1" : 1,
        __DIR__"npc/yao2" : 1,
    ]));                                                                  
                                                                     
  setup();                                                           
}                          