//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "����");                                   
  set ("long", @LONG                                                 
 ���ܳ��������ӣ���Ӱ���ģ������Ӱ���أ��㲻���е������ľ�������
 Ҳ���ɵļӿ��˼��֡�                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"tower",                                         
  "east" : __DIR__"bamboo",                                    
  "west" : __DIR__"bamboo",                                       
  "south" : __DIR__"bamboo",
                                     
]));                                                                 
                                                                     
  setup();                                                           
}