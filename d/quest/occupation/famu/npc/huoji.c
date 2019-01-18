// Created by kuku@sjsh  2003.2
// �ӹ��������ԭ��npc

#include <ansi.h>
inherit NPC;
int ask_jiagong();

string *wood1=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood"});
string *wood2=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood","/d/quest/dazao/material1/pinewood","/d/quest/dazao/material1/rubberwood"});
string *wood3=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood","/d/quest/dazao/material1/pinewood","/d/quest/dazao/material1/rubberwood","/d/quest/dazao/material1/nanwood","/d/quest/dazao/material1/camphorwood"});
string *wood4=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood","/d/quest/dazao/material1/pinewood","/d/quest/dazao/material1/rubberwood","/d/quest/dazao/material1/nanwood","/d/quest/dazao/material1/camphorwood","/d/quest/dazao/material1/pomelowood","/d/quest/dazao/material1/cypresswood"});
string *wood5=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood","/d/quest/dazao/material1/pinewood","/d/quest/dazao/material1/rubberwood","/d/quest/dazao/material1/nanwood","/d/quest/dazao/material1/camphorwood","/d/quest/dazao/material1/pomelowood","/d/quest/dazao/material1/cypresswood","/d/quest/dazao/material1/pearwood","/d/quest/dazao/material1/palmwood"});
string *wood6=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood","/d/quest/dazao/material1/pinewood","/d/quest/dazao/material1/rubberwood","/d/quest/dazao/material1/nanwood","/d/quest/dazao/material1/camphorwood","/d/quest/dazao/material1/pomelowood","/d/quest/dazao/material1/cypresswood","/d/quest/dazao/material1/pearwood","/d/quest/dazao/material1/palmwood","/d/quest/dazao/material1/peachwood","/d/quest/dazao/material1/psandalwood"});
string *wood7=({"/d/quest/dazao/material1/redwood","/d/quest/dazao/material1/firwood","/d/quest/dazao/material1/pinewood","/d/quest/dazao/material1/rubberwood","/d/quest/dazao/material1/nanwood","/d/quest/dazao/material1/camphorwood","/d/quest/dazao/material1/pomelowood","/d/quest/dazao/material1/cypresswood","/d/quest/dazao/material1/pearwood","/d/quest/dazao/material1/palmwood","/d/quest/dazao/material1/peachwood","/d/quest/dazao/material1/psandalwood","/d/quest/dazao/material1/bsandalwood","/d/quest/dazao/material1/sandalwood"});

void create()
{
        set_name("���", ({"huo ji"}));
        set("age", 52);
        set("title","ľ����"); 
        set("gender", "����");
        set("int", 35);
        set("long","������ʿ��Ҫ������ñ�����Ҫ�����ӹ���ԭ�ϡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 40000);
        set("daoxing", 100000);
        set("max_force", 400);
        set("force", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 150);
        set("inquiry", ([    
                "�ӹ�" : (: ask_jiagong :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        tell_object(who,"��λ"+RANK_D->query_respect(who)+"���������ӹ�(ask huo ji about �ӹ�)ľ�ĵ���\n");  
}

int ask_jiagong()
{       
        int i;
        object *inv; 
        object me = this_player();
        object ob = this_object();
                
        if( !me || environment(me) != environment() ) return 0;
        
        if( me->is_busy() || me->is_fighting() ){
                command("say ����æ����˵�ɡ�\n");
                return 1;
        }
     
        if( ob->is_busy() || ob->is_fighting() ){
                command("say �ȵȵȣ�����æ���ء�\n");
                return 1;
        }
       
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query_temp("famu/owned")){
                        me->add("balance",-(200000+random(300000)));
                        message_vision("$N����$nһ"+inv[i]->query("unit")+inv[i]->query("name")+"��\n", me,this_object());
                        message_vision(CYN"$N������üͷ����󲻵��ѻ��Ǹ���$nһЩǮ��\n"NOR,me,ob); 
                        command("say �Ե�Ƭ�̣�һ�����ӹ������Ķ�����\n");
                        ob->start_busy(11);
                        call_out("finish_jiagong",10,me);
                        ob->stop_busy();     
                        return 1;                   
                }
                else{
                        command("say ������û��ԭľ��ô�ӹ���\n");
                        return 1;
                }
        }               
        
        if( me->query("balance") < 1000000){
                command("say ��Ĵ��������𰡣����ܹ�Ǯ�����ɡ�\n"); 
                return 1;
        }
        return 1;
}

int finish_jiagong(object me)
{
        object ob = this_object();
        object newob;
        int i;
        object *inv; 
        
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                switch(inv[i]->query_temp("famu/owned")){
                        case 7:                         
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood7[random(14)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 6:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood6[random(12)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 5:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood5[random(10)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 4:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood4[random(8)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 3:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood3[random(6)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 2:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood2[random(4)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 1:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(wood1[random(2)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                        default: break;
                }
        }
        return 1;
}
