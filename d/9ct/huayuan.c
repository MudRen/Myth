// ������ ����԰ by Calvin
// Modified by kuku@sjsh  2003.5.17

#include <ansi.h>
inherit ROOM;
#include "banned1.h"

void create ()
{
  set ("short", NOR"����԰"NOR);
  set ("long", @LONG

����������������������������������������������������������������������������
������   �����ǻʹ��ĺ�Ժ - "����԰",�����ļ�����,���������۵ľ���    ������
������   ��԰�м���ǿ�"ǧ����(qianzi teng)",����������,һ�ۿ�����    ������
������   ��.��ǰ�����ɵ���ʦ�����۾Ӵ˴����ڵ����书,��������������   ������
������   ��ħ����,ʦ����ֻ��Զ�����,��Ѱ��������֮����.              ������
����������������������������������������������������������������������������

LONG);
        set("exits", ([   
                "up": __DIR__"yi",
        ]));
        set("objects", ([   
        ]));

        set("9ctroom",1);  
        setup();
}

void init() 
{  
        object me=this_player();
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
}  


int do_quit(string arg) 
{  
        write("�����˾�����ʵʵ�İɣ���ֻ��һ��·���ߡ�\n");  
        if (wizardp(this_player())) write("��ֹʹ�ô����\n");  
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

        me->set_temp("sky_enter_time",time()); 
        return ::valid_leave(me, dir);
}