// /d/quest/yaota/baoku1.c  ����
inherit ROOM; 
#include <ansi.h> 
#include <banned1.h> 

void create() 
{ 
         set("short", HIB"����"NOR); 
         set("long", @LONG 
����һ�䲻���ʯ�ң��ıھ��Ǽ�Ӳ����ʯ�� 
LONG); 
         set("objects", ([ 
                "/d/obj/liwu/thousand-cash" : 1, 
         ])); 
         set("exits", ([ 
                "west" : __DIR__"tower3", 
         ])); 
         set("magicroom",1);
        set("alternative_die",1); 
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
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("yaota_enter_time"))>1800){
                        message_vision(CYN"һ����紵��,������ɢ,$NҲ��������ɢȥ��\n"NOR,obj[i]);
                        if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        obj[i]->dismiss_team(); 
                        obj[i]->delete_temp("teamqy");
                        message("vision",CYN"һ����Ӱ����һ�����̴�ħ������Ʈ�˳���!\n"NOR,room,({obj[i]}));
                        call_out("kick_ob",60);
                        return;
                }
        }
        call_out("kick_ob",60);
}
void alternative_die(object who) 
{ 
        object killer,corpse; 
        killer = who->query_temp("last_damage_from"); 
 
        if (userp(who)) { 
                message_vision("$N���ˡ�\n",who); 
                who->set("kee",10);        who->set("sen",10); 
                if(who->query("eff_kee")<10) who->set("eff_kee",10); 
                if(who->query("eff_sen")<10) who->set("eff_sen",10); 
                who->set_temp("hell_died",1); 
                if(!killer) killer=who;
//              if( objectp(corpse = CHAR_D->make_corpse(who, killer)) ) 
//                      corpse->move(this_object()); 
 
                all_inventory(this_object())->remove_killer(who); 
                who->dismiss_team(); 
                who->delete_temp("teamqy");
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

