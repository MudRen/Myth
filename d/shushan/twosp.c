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
  "north" : __DIR__"two3",                                                                             
  "south" : __DIR__"two2",
  "west" : __DIR__"two5",
  "east" : __DIR__"two2",
                                     
]));                                                                 
    set("objects",([
        __DIR__"obj/fbook" : 1,
    ]));                                                                     
  setup();                                                           
}