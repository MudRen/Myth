inherit ROOM;
#include <ansi.h>
#include "banned1.h" 

void create()
{
        set("short", HIB"�������"NOR);
        set("long", @LONG

����������������������������������������������������������������
������  ���������ˣ�û��һ������Ϊ����û��ǲ�Ҫ�Ҵ�Ŷ��������
����������������������������������������������������������������

LONG);
        set("exits", ([ 
               "up" : __DIR__"tower1",
        ]));
        set("objects", ([ 
        ]));
        set("magicroom",1);
        setup();
}

void init() 
{  
//      object me=this_player();
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        
}  

int do_quit(string arg) 
{  
        write("�㲻�����������������\n");  
        if (wizardp(this_player())) write("��ʦ�����ͬһ·���ڵ�banned.h�ĵ���\n");  
        return 1;  
}  

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) write("�㲻�����������������\n");    
        command("cast transfer");
        return 1;
}

int do_exert(string arg) { 
        if(!arg) return 0;
        if(arg !="recover" && arg != "heal" && arg != "refresh") return 0;
        command("exert "+arg);  
}

int valid_leave(object me, string dir)
{
        object ridee;
        ridee=me->ride();


        if( dir=="up" && !userp(me))
                return 0;

        if (dir=="up") {
                if( me->query_temp("ridee") )
                        return notify_fail(WHT"�㻹���ȴ������������ɡ�\n"NOR);
        }

        me->set_temp("yaota_enter_time",time());

        return ::valid_leave(me, dir);
}