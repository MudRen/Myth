// Room: /d/quest/dyzz/greenland.c

#include <ansi.h>
inherit ROOM;
#include "banned.h"

void create()
{
        set("short", "干地");
        set("long", @LONG
你脚下的沼泽已经不见，一片小小的干地呈现在你的眼前。你长出了一口
气，危险似乎离的远了些。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"zhaoze9",
                "east" : __DIR__"zhaoze8",
        ]));
        set("resource/water",1);
        set("alternative_die",1);
        set("dyzzroom",1); 

        setup();
}

void init()
{
        object ob;
        string outexit;
        if( interactive( ob = this_player())){
                if(query("exits/east")) 
                        delete("exits/east");
                outexit = __DIR__"zhaoze"+(string)( random(3)+6)+ ".c";
                set("exits/east", outexit);
        }
        add_action("do_fillwater", "fillwater");
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        if (ob->query("env/invisibility"))  
            ob->delete("env/invisibility");
       
        if( !wizardp(ob) && userp(ob) ) {        
                remove_call_out("kick_ob");
                call_out("kick_ob",60);
        }        
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
//      string dir;

        if( !arg || arg=="" ) return notify_fail("你要往什么东西里灌水？\n");

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                        if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water") ) {
                                ob = list[i];                         
                                can_fillwater = 1;      
                                ob->set("liquid", ([    
                                        "type": "water",
                                        "name": "清水",
                                        "remaining": 15,
                                        "drunk_apply": 6,
                                ]) );
                                write("你从井里装满了清水! \n");
                                return 1;
                        }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}

void kick_ob()
{
        object room,*obj;
        int i;

        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("dyzz_enter_time"))>1800){
                        message_vision(CYN"一阵清风吹来,清烟消散,$N也随着清烟散去！\n"NOR,obj[i]);
                        if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        obj[i]->dismiss_team(); 
                        message("vision",CYN"一个人影随着一阵清烟从魔幻世界飘了出来!\n"NOR,room,({obj[i]}));
                        call_out("kick_ob",60);
                        return;
                }
        }
        call_out("kick_ob",60);
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