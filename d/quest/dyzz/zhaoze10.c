// Room: /d/quest/dyzz/zhaoze10.c
// Created by kuku@sjsh 2003.3

#include <ansi.h>
#include <room.h>
inherit ROOM;
#include <banned.h>
string *list=({"yg-level0","yg-level1","yg-level2","yg-level3","yg-level4","yg-level5","yg-level6","yg-level7","yg-level8","yg-level9","yg-level10",
        });

void create()
{
        object obj;
        int i,num;
        set("short", "��������");
        set("long", @LONG
�����ڴ��ڱ鲼ʪ��������У��������ճ�š���ʱ��������������Ұ�޵�
�����������˲����������������۳�ʪ�������������������Ķ����ˣ���
�ؼ�·�ֻʣ����һ���ˡ��������һ��ǳһ�ŵģ��о���ʱ���б��ݽ�ȥ
��Σ�ա�
LONG
        );
        num = random(3)+3;
        set("exits", ([ 
                "west" : __DIR__"mfoot",
                "east"  : __DIR__"zhaoze9",
        ]));
        set("item_desc", ([   
                "mud" : "��ʪ�������������һͷ���˶��ɵľ��ޣ�����������¡�\n",
                "����" : "��ʪ�������������һͷ���˶��ɵľ��ޣ�����������¡�\n",
        ]));
        

        set("objects", ([   
                __DIR__"obj/wetmud" : 1,
                __DIR__"obj/jadesword" : 1,
                "obj/money/gold": 1,
                __DIR__"npc/yg-level8" : 1,
                __DIR__"npc/yg-level5" : 1,
                __DIR__"npc/yg-level6" : 1,
                __DIR__"npc/yg-level3" : 1,  
        ]) );

        set("npc_num",num);
        set("alternative_die",1);
        set("dyzzroom",1); 
        set_heart_beat(180);

        setup();
}

void heart_beat()
{      
        reset();
}

void reset() 
{
        object guai;
        int i;
 
        this_object()->add_temp("npc_times",1);
        if (this_object()->query_temp("npc_times")>10){
                this_object()->set_temp("npc_times",1);
                if(this_object()->qurey("npc_num")> 0){
                        for(i=0;i<this_object()->query("npc_num");i++) { 
                                guai = new("/d/quest/dyzz/npc/"+list[random(sizeof(list))]);
                                guai->move(this_object());
                        }
                }
        }
        ::reset();
}

void init()
{       
        object me = this_player();
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
       
        if( !wizardp(me) && userp(me) ) {        
                remove_call_out("kick_ob");
                call_out("kick_ob",60);
        }        
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
                if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
                        corpse->move(this_object());  
                all_inventory(this_object())->remove_killer(who);               
                who->remove_ride();  
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
