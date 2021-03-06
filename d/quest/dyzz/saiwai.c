// Room: /d/quest/dyzz/saiwai.c

#include <ansi.h>
inherit ROOM;
#include "banned.h"  

void create()
{
        set("short", "野外");
        set("long", @LONG
地势到这是豁然开朗，你的西边是一望无际的沼泽地。这片沼泽地里
时常有怪兽出没，到了那里的人很少有活着回来的。冥冥中仿佛已有种邪
恶的力量，任何人随时都有可能突然像野狗般死在沼泽中。
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
        write("进来了就老老实实的吧，你只有一条路可走。\n");  
        if (wizardp(this_player())) write("禁止使用此命令。\n");  
                return 1;  
}   

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) write("你不能在这里用这条命令。\n");    
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
                message_vision("$N死了。\n",who);  
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
                message_vision("$N死了。\n",who);  
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
                        return notify_fail(WHT"你还是先从坐骑上下来吧。\n"NOR);
        }

        me->set_temp("dyzz_enter_time",time());
        return ::valid_leave(me, dir);
}