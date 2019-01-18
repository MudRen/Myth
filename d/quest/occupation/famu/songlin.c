#include <ansi.h>
inherit ROOM;
int i=0;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
һƬ�ô������,�м����������������ɵط�ľ,�־����ͬ��С�� 
ľ��,һ�ζεĶѳ���һ��Сɽ,�������ľ��שҤ����Ҫȼ��. 
LONG);

        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"fmxh",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"obj/axe" : 9,
                __DIR__"npc/famugong" : 1,
        ]));

        setup();
}

void init()
{  
        add_action("do_kan","kan");
}

int do_kan(string str)
{ 
        object me,ob;
        me=this_player();
        if ((!str)||(str!="wood")) 
                return notify_fail("��Ҫ��ʲô?\n");
                
        if (!(ob=me->query_temp("weapon"))||(string)ob->query("id")!= "famuaxe")
                return notify_fail("������ȥ�Ұѿ�ľ���Ӱ�!\n");
                
        if( me->is_busy() ) return notify_fail("�����ں�æ�����ܿ�����\n");

        if (me->query_temp("work/kan")==1){   
                message_vision("$N����󸫿�������!\n",me);
                me->start_busy(random(6));   
                i=++i;
                if (i<8){
                        me->receive_damage("kee",(int)me->query("max_kee")*10/100);                     
                        return 1;
                }
                me->set_temp("work/kan",2);            
                message_vision("$N���Ŷѵø߸ߵ��ɲ�����һ�ڳ��������ڸ�����!\n",me);
                i=0;
                return 1;
        }        
        if (me->query_temp("work/kan")==2) 
                return notify_fail("��հѻ���꣬������ȥ��๤�����!\n");
        return notify_fail("����û���Ӧ������๤����к�!\n");
}

int valid_leave(object me, string dir)
{   
        object ob;
        ob=present("famuaxe",me);   
        if (dir=="north" && ob){   
                message_vision(HIR+"$N����һ�Ѵ�ͷ��ת���߳�������!\n"+NOR,me);
                ob->move(environment(me));
                i=0;
                return 1;
        }
        return ::valid_leave(me, dir);
}
