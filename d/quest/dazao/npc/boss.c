// Created by kuku@sjsh  2003.2
// �ӹ��������ԭ��npc

#include <ansi.h>
inherit NPC;
int ask_jiagong();

string *metal1=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze"});
string *metal2=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper"});
string *metal3=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel"});
string *metal4=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel","/d/quest/dazao/material2/nickeliron","/d/quest/dazao/material2/nickelsteel"});
string *metal5=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel","/d/quest/dazao/material2/nickeliron","/d/quest/dazao/material2/nickelsteel","/d/quest/dazao/material2/whitesilver","/d/quest/dazao/material2/whitegold"});
string *metal6=({"/d/quest/dazao/material2/yellowcopper","/d/quest/dazao/material2/yellowiron","/d/quest/dazao/material2/bronze","/d/quest/dazao/material2/rediron","/d/quest/dazao/material2/purplecopper","/d/quest/dazao/material2/castiron","/d/quest/dazao/material2/caststeel","/d/quest/dazao/material2/nickeliron","/d/quest/dazao/material2/nickelsteel","/d/quest/dazao/material2/whitesilver","/d/quest/dazao/material2/whitegold","/d/quest/dazao/material2/yellowgold","/d/quest/dazao/material2/purplegold"});

void create()
{
        set_name("�ϰ�", ({"lao ban", "boss"}));
        set("age", 52);
        set("title","������");
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
        tell_object(who,"��λ"+RANK_D->query_respect(who)+"���������ӹ�(ask boss about �ӹ�)��ʯ����\n");  
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

        if( me->query("balance") < 1000000){ 
                command("say ��Ĵ��������𰡣����ܹ�Ǯ�����ɡ�\n");  
                return 1; 
        }
       
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query_temp("wakuang/owned")){
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
                        command("say ������û�п�ʯ��ô�ӹ���\n");
                        return 1;
                }
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
                switch(inv[i]->query_temp("wakuang/owned")){
                        case 7:                         
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(metal6[random(13)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 6:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(metal5[random(11)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 5:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(metal4[random(9)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 4:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(metal3[random(7)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 3:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(metal2[random(5)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 2:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new(metal1[random(3)]);
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                                break;
                        case 1:
                                command("say ��Ҫ�Ķ����ӹ����ˡ�\n");
                                destruct(inv[i]);
                                newob=new("/d/quest/dazao/material2/yellowcopper");
                                message_vision("$N����$nһ"+newob->query("unit")+newob->query("name")+"��\n"NOR,ob,me); 
                                newob->move(me);
                                newob->set_temp("dazao_owner",newob->query("id"));
                        default: break;
                }
        }
        return 1;
}
