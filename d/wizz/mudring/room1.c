// /d/wizz/mudring/room1.c �ư�

#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", HIR"õ��ư�"NOR);
        set("long", @LONG
����Χ������(table)����������(chair)��Ʒ�ƣ��ò���ң���ڡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"room2",
                "north" : "/u/mudring/workroom",
        ]));
        
    set("item_desc", ([
            "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
            "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��\n",
        ]));
                                        

        set("objects",([
        __DIR__"npc/shinv" : 1,
        ]));
        
        
        setup();
}

void init()
{
        add_action("do_tap", "tap");
        add_action("do_tap", "knock");
        add_action("do_sit", "sit");
}


int do_tap(string arg)
{

        object me;
        object cui;

        if (!arg || (arg != "desk" && arg != "table"))
        {
                return notify_fail("��Ҫ��ʲô��\n");   
        }
                
        me = this_player();     
        if( !objectp(cui = present("shi nv", environment(me))) )
                return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о�һ��ʧ�䡣\n");
                                
        if( !me->query_temp("marks/sit") )  
                return notify_fail("�����������ӣ����е��˶���ͷ�Ȼ�ؿ����㣬"
                        +"\n��ͻȻ�о��Լ����޴���\n");
        
    if( me->query_temp("marks/served") )
    {
        message_vision("ʹŮ���ͷ��ض�$N˵�����ո������������ž�Ҫ��"+
                                "���Ǹ���Ͱ���ǰ�?��\n", me);
        return notify_fail("");
    }

        message_vision("$N��������ǰ��������������棬ʹŮһ˦С�磬�����к���\n", me);
        
        cui->serve_tea(me) ;

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

        return 1;
}


void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

        if ( !arg || (arg != "chair") )
                return notify_fail("��Ҫ��ʲô���棿\n");       
        
        if (this_player()->query_temp("marks/sit"))
                return notify_fail("���Ѿ����˸���λ�ˡ�\n");   
                        
        this_player()->set_temp("marks/sit", 1);
        return notify_fail("�����˸���λ���£������ϲ衣\n");   
}


int valid_leave(object me, string dir)
{

        if (  (dir == "north")
           && ( present("booze", this_player())
                || present("wine", this_player()) ) 
           && objectp(present("shi nv", environment(me)))
           && me->query("id") != "xianzi" && me->query("id") != "mudring" )
        switch ( random(2) ) 
        {
        case 0: 
         return notify_fail
                ("ʹŮ����һƲ���Ա��˺����˻����������߻��ﻹ����һЩ��СŮ��Ҳ���������أ�\n");
         break;
        case 1:
         message_vision("ʹŮ��$N���˸��򸣣��ϰ�涨����ʳ���ô����ưɡ�\n", me);
         return notify_fail("\n");
         break;
        }
        
        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");
        return ::valid_leave(me, dir);
}



