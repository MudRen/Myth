//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "����");                                   
  set ("long", @LONG                                                 
һ�����������������ǰ�������ͷ�����㾪�ȵط��֣��㲢û����·��                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"saveling",                                      
]));                                                                                                                          
    set("objects",([
        __DIR__"npc/mingwang" : 1,
    ]));   
  setup();                                                           
}
int valid_leave(object me, string dir)
{

   if (dir == "north" ) {
        if (objectp(present("zhenyu mingwang", environment(me))))
   return notify_fail("����������ס·�����������\n");
        }   
        return ::valid_leave(me, dir);
}
