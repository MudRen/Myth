// /d/quest/yaota/baoku1.c  ����
inherit ROOM;  
#include <ansi.h> 
#include <banned1.h>

void create() 
{ 
        set("short", HIW"�����ı���"NOR); 
        set("long", @LONG 
����һ�䲻���ʯ�ң��ıھ��Ǽ�Ӳ����ʯ�� 
LONG); 
        set("objects", ([ 
     ])); 
        set("exits", ([ 
                "north" : __DIR__"jiu", 
        ])); 
        set("9ctroom",1);
        setup(); 
} 

void init()
{
        object me=this_player();
        add_action("do_quit",banned_action);  
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
                   
        if( !wizardp(me) && userp(me) ) {        
                remove_call_out("kick_ob");
                call_out("kick_ob",60);
        }
        add_action("do_cast","cast");
        add_action("do_exert","exert");
}

void kick_ob()
{
        object room,*obj;
        int i;

        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("sky_enter_time"))>1800){
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

