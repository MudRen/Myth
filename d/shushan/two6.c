//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "�ڶ����Թ�");                                   
  set ("long", @LONG                                                 
������ʯ�ڵ��Թ���һ��ŨŨ�����������ڿ����                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"two2",                                                                             
  "south" : __DIR__"two2",
  "west" : __DIR__"two2",
  "east" : __DIR__"two7",
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/yao1" : 2,
        __DIR__"npc/yao2" : 2,
    ]));                                                                     
  setup();                                                           
}