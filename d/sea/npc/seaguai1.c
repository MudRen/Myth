// Created by kuku@sjsh 2003.5.17
 
inherit NPC; 
#include <ansi.h>
       
void create() 
{ 
        if(random(2)==0)  
                set_name( "������", ({"old guai","guai"})); 
        else  
                set_name( "С����", ({"small guai","guai"})); 
        set("age", 50+random(100)); 
        set("gender", random(2)?"����":"Ů��"); 
        set("attitude", "aggressive"); 
        set("per", random(20)+1); 
        set("str", 100); 
        set("cor", 40); 
        set("con", 40); 
        set("int", 40); 
        set("spi", 40); 
        set("cps", 40); 
        set("kar", 40); 
        set("max_gin", 1000);
        set("kee", 5000); 
        set("max_kee", 5000); 
        set("eff_kee", 5000); 
        set("sen", 5000); 
        set("max_sen", 5000); 
        set("eff_sen", 5000); 
        set("force", 5000); 
        set("max_force", 5000); 
        set("mana", 5000); 
        set("max_mana", 5000); 
        set("force_factor", 300);
        set("mana_factor", 300);
        set("level",random(500)+1);
        set("combat_exp", 6000000);
        set("daoxing", 6000000);
        set("food", 10000); 
        set("water", 10000); 
        set_weight(30000); 
        
        set_skill("literate", 300);
        set_skill("unarmed", 300);
        set_skill("force", 300);
        set_skill("buddhism", 300);
        set_skill("lotusforce", 300);
        set_skill("staff", 300);
        set_skill("lunhui-zhang", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("spells", 300);
        set_skill("jienan-zhi", 300);   
        set_skill("lotusmove", 300);
        map_skill("force", "lotusforce");
        map_skill("spells", "buddhism");
        map_skill("staff", "lunhui-zhang");
        map_skill("parry", "lunhui-zhang");
        map_skill("dodge", "lotusmove");
        map_skill("unarmed", "jienan-zhi");
        
        set_temp("apply/armor", 800);
        set_temp("apply/dodge", 200);
        set_temp("apply/armor_vs_force",400); 
        set_temp("apply/armor_vs_spells",400); 
        create_family("�Ϻ�����ɽ",2 , "����");
        set("title",HIM"�˾�"NOR);
        set("class", "bonze");
        set("no_steal",1); 
        set("taskguai",1); 
        
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({                
                (: perform_action,"staff", "pudu" :),
                (: cast_spell, "bighammer" :),
        }) );
        
        setup();
        carry_object("/d/9ct/zb/tianjia")->wear();
        carry_object("/d/9ct/zb/pudu")->wield();
}

void init () 
{       
        object me=this_object(); 
        object who=this_player(); 
        if(userp(who)) 
        kill_ob(who); 
        ::init(); 
} 

void destructing() 
{ 
        destruct(this_object()); 
} 

void heart_beat() 
{ 
        object guai = this_object(); 
        if ( !is_fighting() 
        && query("eff_kee") >= query("max_kee") / 2 
        && !query_skill("tonsillit",1) 
        && !query_skill("zixia-shengong",1) 
        && query("eff_kee") <  query("max_kee") ) 
        { 
            set("eff_kee",query("max_kee")); 
            set("eff_sen",query("max_sen")); 
        } 
        if (query("kee") < query("eff_kee")-10 ) 
            command("exert recover"); 
        if (query("sen") < query("eff_sen")-10) 
            command("exert refresh"); 
        if (query("force") < query("max_force")/10) 
            command("cast transfer"); 
        ::heart_beat(); 
} 
   
void kill_ob (object ob) 
{ 
        object me = this_object(); 
        me->set_leader(ob);
        ::kill_ob(ob); 
}

void die()   
{ 
        object killer;  
        int exp,exp_reward,pot_reward,dx_reward;
        
        killer = this_object()->query_temp("last_damage_from");   
        exp=(killer->query("combat_exp")+killer->query("daoxing"))/1000; 
        if(exp<6000) { 
                exp_reward=150+exp/6; 
                pot_reward=60+exp/30; 
                dx_reward =150+exp/6;
        } 
        else if(exp<10000) { 
                exp_reward=300+exp/60; 
                pot_reward=120+exp/600;         
                dx_reward =300+exp/6;   
        } 
        
        if (userp(killer)){             
                killer->add("combat_exp",exp_reward);
                killer->add("potential",pot_reward);
                killer->add("daoxing",dx_reward);
                tell_object(killer,HIY"��õ���"+COMBAT_D->chinese_daoxing(dx_reward)+"���к�"+exp_reward+"����ѧ�����Լ�"+pot_reward+"��Ǳ�ܵĽ�����\n" NOR);
        } 
        destruct(this_object());
}
