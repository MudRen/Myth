// Room: /d/quest/dyzz/zhaoze9.c
// Created by kuku@sjsh 2003.3

#include <ansi.h>
#include <room.h>
inherit ROOM;
#include <banned.h>
int drop_him(object me);

void create()
{
        object san, sna;
        set("short", "��������");
        set("long", @LONG
�����ڴ��ڱ鲼ʪ��������У��������ճ�š���ʱ��������������Ұ�޵�
�����������˲����������������۳�ʪ��������������������Ķ����ˣ���
�ؼ�·�ֻʣ����һ���ˡ��������һ��ǳһ�ŵģ��о���ʱ���б��ݽ�ȥ
��Σ�ա�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"zhaoze10",
                "north" : __DIR__"zhaoze1",
                "east"  : __DIR__"greenland",
                "down"  : __DIR__"quickmud9",
        ]));
        set("objects", ([   
                __DIR__"obj/wetmud" : 1,
                __DIR__"obj/skeleton" : 1,
                "/obj/money/gold": 1,
        ]) );

        set("alternative_die",1);
        set("dyzzroom",1); 

        setup();
        san = present("wetmud", this_object());
        sna = present("gold", this_object());
        sna->move(san);
        sna = present("skeleton", this_object());
        sna->move(san); 
}

void init()
{       object ob;
        object jade;
        int water, food, bellicosity;
        string outexit;
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
        message_vision(HIW"$NͻȻ�е��ŵ�������ģ��޴�������", me);
        message_vision("$N���һ�������ã����������������ˡ�\n", me);
        message_vision("$N����������֮�У���\n"NOR, me); 
        me->move(__DIR__"quickmud9");
        return 1;
}
        
int do_pull ( string arg)
{
        object me, who;
        object room;
        me = this_player();
        if ( !arg  ) return notify_fail("��Ҫ��˭������\n");
        room = load_object(__DIR__"quickmud9");
        if(!objectp(who = present(arg, room)) ||  !living(who))
                return notify_fail("������û������ˡ�\n");
        message_vision(HIW"$N�þ�ȫ����������$n�������о��˳�����\n"NOR, me,who);
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
                        message_vision(CYN"һ����紵��,������ɢ,$NҲ��������ɢȥ��\n"NOR,obj[i]);
                        if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        obj[i]->dismiss_team(); 
                        message("vision",CYN"һ����Ӱ����һ�����̴�ħ������Ʈ�˳���!\n"NOR,room,({obj[i]}));
                        call_out("kick_ob",60);
                        return;
                }
        }
        call_out("kick_ob",60);
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
        
        if ( !userp(me) && dir == "down")
                return notify_fail(""+me->query("name")+"��ԭ��ת��һȦ��\n");
        
        return ::valid_leave(me, dir);
}
