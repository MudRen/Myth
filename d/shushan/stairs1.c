//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "��һ���Թ�");                                   
  set ("long", @LONG                                                 
������ʯ�ڵ��Թ���ֻ���Ϸ��и�����Ӧ����ͨ��ڶ���ġ�                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "up" : __DIR__"two1",                                                                             
  "west" : __DIR__"one7",                                       
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/yuanhun" : 1,
    ]));                                                                           
  setup();                                                           
}

int valid_leave(object me, string dir)
{

   if (dir == "up" ) {
        if (objectp(present("yuan hun", environment(me))))
   return notify_fail("ԩ����ס·�����������\n");
        }   
        return ::valid_leave(me, dir);
}
                        