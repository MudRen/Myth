//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "�ڶ����Թ�");                                   
  set ("long", @LONG                                                 
������ʯ�ڵ��Թ���ֻ���Ϸ��и�����Ӧ����ͨ�������ġ�                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "up" : __DIR__"three1",                                                                             
  "north" : __DIR__"two7",                                       
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/fool" : 1,
        __DIR__"obj/fbook" : 1,
    ]));                                                                      
  setup();                                                           
}

int valid_leave(object me, string dir)
{

   if (dir == "up" ) {
        if (objectp(present("fool", environment(me))))
   return notify_fail("��û�����й�ס·�𣡡�\n");
        }   
        return ::valid_leave(me, dir);
}
