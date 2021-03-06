// Room: /d/quest/dyzz/zhaoze4.c
// Created by kuku@sjsh 2003.3

#include <ansi.h>
#include <room.h>
inherit ROOM;
#include "banned.h"
int drop_him(object me);
        
void create()
{
        set("short", "蛮荒沼泽");
        set("long", @LONG
你现在处在遍布湿泥的沼泽中，泥巴松软粘脚。不时可听到隐隐的有野兽的
嚎叫声，令人不寒而栗；除了满眼潮湿松软的泥土，看不见别的东西了；天
地间仿佛只剩下你一个人。你脚下伸一脚浅一脚的，感觉随时都有被陷进去
的危险。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"zhaoze0",
                "north" : __DIR__"zhaoze7",
                "south" : __DIR__"zhaoze8",
                "east"  : __DIR__"zhaoze3",
                "down"  : __DIR__"quickmud4",
        ]));
        set("objects", ([   
                __DIR__"obj/wetmud" : 1,
                "/obj/money/gold": 1,
                "/obj/money/silver": 1,
        ]) );
        set("alternative_die",1);
        set("dyzzroom",1); 

        setup();
}

void init()
{       object ob;
        object jade;
        int water, food, bellicosity;
//      string outexit;
        if( interactive( ob = this_player())){
                water = ob->query("water");
                food = ob->query("food");
                bellicosity = ob->query("bellicosity");
                water -= (random(4)+ 1) * water / 10;
                food -= (random(2)+ 1) * water / 10;
                bellicosity += random(10);
                ob->set("water", water);
                ob->set("food", food);
                ob->set("bellicosity", bellicosity);    
                if( !objectp(jade = present("jade", ob))){
                        if( random(200)< 2)               
                                drop_him(ob);
                }
                else{
                        if( random(1000)< 2)    
                                drop_him(ob);
                }
        }
        add_action("do_pull", "pull");
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

int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1;

}

int dropnow(object me)
{
        message_vision(HIW"$N突然感到脚底软绵绵的，无处着力！", me);
        message_vision("$N大叫一声“不好！”，可是来不及了…\n", me);
        message_vision("$N已陷身沼泽之中！！\n"NOR, me);
        me->move(__DIR__"quickmud4");
        return 1;
}
 
int do_pull ( string arg)
{
        object me, who;
        object room;
        me = this_player();
        if ( !arg  ) return notify_fail("你要拉谁上来？\n");
        room = load_object(__DIR__"quickmud4");
        if(!objectp(who = present(arg, room)) ||  !living(who))
                return notify_fail("沼泽里没有这个人。\n");
        message_vision(HIW"$N用尽全身力量，将$n从沼泽中救了出来。\n"NOR, me,who);
        who->move(__FILE__);
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

int valid_leave(object me, string dir)
{
        
        if ( !userp(me) && dir == "down" )
                return notify_fail(""+me->query("name")+"在原地转了一圈。\n");
        
        return ::valid_leave(me, dir);
}
