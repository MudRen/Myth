//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
#include <ansi.h>                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIG"���������"NOR);                                   
  set ("long", @LONG                                                 
��������ڣ�������һ��ʯ��(door)��                                           
LONG);                                                          
        set("item_desc", ([
                "door": @TEXT
��Ӳ�ޱȵ�ʯ�ţ�����Ҫ������(break)��
TEXT        ]) );
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "out" : __DIR__"bamboo4",      
]));                            
set("objects",([__DIR__"obj/jar":1,]));                                     
                                                                     
  setup();                                                           
}                                  

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object room;
        object me = this_player();

        if (objectp(present("gui wang", environment(me))) ||objectp(present("jar", environment(me)))) 
                return notify_fail("ƾ���Լ����������´򲻿���\n");

        if (query("exits/north"))
                return notify_fail("�����Ѿ������ˡ�\n");

        if (!arg || (arg != "men" && arg != "door" && arg != "north"))
                return notify_fail("��Ҫ����ʲô��\n");

        if(!( room = find_object(__DIR__"one1")) )
                room = load_object(__DIR__"one1");
        if(objectp(room))
        {
                set("exits/north", __DIR__"one1");
                write(CYN"����ͻȻ������һ������֮�С�\n");
                write("����˵������������������ɡ���\n");
                write("����һȭ��ʯ�Ŵ�÷��飡\n");
                write("����ͻȻ��ʧ��һ������֮�С�\n"NOR);
                room->set("exits/south", __FILE__);
                
        }

        return 1;
}