// Room: /d/quest/dyzz/quickmud1.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_sanddrop(object me, object obj);

void create()
{
        set("short", "������");
        set("long", @LONG
���Ծ���������֮�У�����û��һ�������ĵط�����һ����������ȥ��
����������(pull)��һ�ѣ�������뿪������±ȵ��컹�ѡ����ƺ���
�������ˡ�
LONG
        );

        set("NONPC",1);
        set("no_move",1);
        setup();
}

void init()
{       object ob;
        if( interactive( ob = this_player())){
                remove_call_out("sinking");
                call_out("sinking", 1, ob);
        }
        add_action("do_accept","accept");
        add_action("do_cast","cast");
        add_action("do_quit","quit");
        
        if( !wizardp(ob) && userp(ob) ) {        
                remove_call_out("kick_ob");
                call_out("kick_ob",900);
        }        
}

int sinking(object ob)
{
        int i;
        int damage;
        if( ob &&  environment(ob) == this_object()){
                message_vision(HIW"$N������ɳ��������һЩ����\n"NOR, ob);
                message_vision("$N�����ھ����п��˳�������\n", ob);
                damage = random(20)+5;
                i =  (int)ob->query("kee");
                ob->set("kee", i - damage);
                if( environment(ob) == this_object())
                        call_out("sinking",random(5)+5, ob);    
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
                        message_vision(CYN"һ����紵��,������ɢ,$NҲ��������ɢȥ��\n"NOR,obj[i]);
                        if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        obj[i]->dismiss_team(); 
                        message("vision",CYN"һ����Ӱ����һ�����̴�ħ������Ʈ�˳���!\n"NOR,room,({obj[i]}));
                        call_out("kick_ob",900);
                        return;
                }
        }
        call_out("kick_ob",900);
}

int do_accept(string arg) 
{  
        write("���ݽ����˻�����ʲô����û�˾���Ϳްɡ�\n");  
        return 1;  
}   

int do_cast(string arg) 
{  
        write("���ݽ����˻�����ʲô����û�˾���Ϳްɡ�\n");  
        return 1;  
}   

int do_quit(string arg) 
{  
        write("���ݽ����˻�����ʲô����û�˾���Ϳްɡ�\n");  
        return 1;  
}   

