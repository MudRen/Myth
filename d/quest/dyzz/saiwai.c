// Room: /d/quest/dyzz/saiwai.c

#include <ansi.h>
inherit ROOM;
#include "banned.h"  

void create()
{
        set("short", "Ұ��");
        set("long", @LONG
���Ƶ����ǻ�Ȼ���ʣ����������һ���޼ʵ�����ء���Ƭ�������
ʱ���й��޳�û������������˺����л��Ż����ġ�ڤڤ�з·�������а
����������κ�����ʱ���п���ͻȻ��Ұ�������������С�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"saiwai2",
        ]));    
        set("alternative_die",1); 
        set("dyzzroom",1); 
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

void alternative_die(object who)  
{  
        object killer,corpse;
        killer = who->query_temp("last_damage_from");  
   
        if (userp(who)) {  
                message_vision("$N���ˡ�\n",who);  
                who->set("kee",10); who->set("sen",10);  
                if(who->query("eff_kee")<10) who->set("eff_kee",10);  
                if(who->query("eff_sen")<10) who->set("eff_sen",10);           
                if(!killer) killer=who; 
//        if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
//                corpse->move(this_object());  
                all_inventory(this_object())->remove_killer(who);               
                who->remove_ride(); 
                who->dismiss_team();   
                who->delete_temp("last_fainted_from");  
                who->move("/d/city/kezhan");  
        }  
        else {  
                if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
                        corpse->move(this_object());  
                message_vision("$N���ˡ�\n",who);  
                who->reward();    
                destruct(who);  
        }  
}

int valid_leave(object me, string dir)
{
        object ridee;
        ridee=me->ride();

        if( dir=="up" && !userp(me)) 
                return 0; 

        if (dir=="west") {
                if( me->query_temp("ridee") )
                        return notify_fail(WHT"�㻹���ȴ������������ɡ�\n"NOR);
        }

        me->set_temp("dyzz_enter_time",time());
        return ::valid_leave(me, dir);
}