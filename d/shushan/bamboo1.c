
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "����");                                   
  set ("long", @LONG                                                 
 ���ܳ��������ӣ���Ӱ���ģ������Ӱ���أ��㲻���е������ľ�������
 Ҳ���ɵļӿ��˼��֡�                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"bamboo2",                                         
  "east" : __DIR__"bamboo",                                    
  "west" : __DIR__"bamboo",                                       
  "south" : __DIR__"bamboo",
                                     
]));                                                                 
                                                                     
  setup();                                                           
}