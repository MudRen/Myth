// created by kuku@sjsh
 
inherit NPC; 
#include <ansi.h>

string *list1=({
        "yaxe","yblade","yfork","yhammer","ymace","yspear","ystaff","ysick","ysword","ywhip",
});

string *list2=({
        "axe","blade","fork","hammer","mace","spear","staff","stick","sword","whip",
});

string *list3=({
        "yarmor","yboots","ycloth","yhands","yhead","yneck","yring","yshield","ysurcoat","ywaist","ywrists",
});

string *list4=({
        "armor","boots","cloth","hands","head","neck","ring","shield","surcoat","waist","wrists",
});

void setname() 
{ 
       mapping name;
       name=__DIR__"name"->random_name("yaoguai");
        set_name(name["name"], name["id"]);         
} 
       
void create(int value,int level) 
{ 
        setname(); 
        if(value==0) value=random(40)+10; 
//        if(level==0) level=random(40)+10; 
        level = 25;
        set("age", 100+random(80)); 
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
        set("kee", value*200); 
        set("max_kee", value*200); 
        set("eff_kee", value*200); 
        set("sen", value*200); 
        set("max_sen", value*200); 
        set("eff_sen", value*200); 
        set("force", value*300); 
        set("max_force", value*300); 
        set("mana", value*300); 
        set("max_mana", value*300); 
        set("level",random(500)+1);
        set("combat_exp",level*1500000); 
        set("daoxing",level*1500000); 
        set("food", 10000); 
        set("water", 10000); 
        set_weight(30000); 
        
        set_skill("unarmed", level*20); 
       set_skill("dodge", level*20); 
       set_skill("force", level*20); 
       set_skill("spells", level*20); 
       set_skill("parry", level*20); 
        set_skill("literate", 250);
        set_skill("spear", level*20);
        set_skill("wuyue-spear", level*20);
        set_skill("pingtian-dafa", level*20);
        set_skill("moyun-shou", level*20);
        set_skill("huomoforce", level*20);
        set_skill("moshenbu", level*20);
        map_skill("spells", "pingtian-dafa");
        map_skill("unarmed", "moyun-shou");
        map_skill("force", "huomoforce");
        map_skill("spear", "wuyue-spear");
        map_skill("parry", "wuyue-spear");
        map_skill("dodge", "moshenbu");
        set("force_factor", level*10);
        set("mana_factor", level*10);
        
        set_temp("apply/armor", level*40); 
        set_temp("apply/damage", level*10); 
        set_temp("apply/attack", level*10); 
        set_temp("apply/dodge", level*10); 
        set_temp("apply/spells", level*10); 
        set_temp("apply/armor_vs_force",level*20); 
        set_temp("apply/armor_vs_spells",level*20); 
        create_family("���ƶ�",2 , "����");
        set("title",WHT"��������"NOR);       
        set("no_steal",1); 
        set("taskguai",1); 
        set("chat_chance", 5);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action,"spear", "fengchan" :),
                (: cast_spell, "sanmei" :), 
        }) ); 
        setup(); 
        carry_object("/d/9ct/zb/tianjia")->wear();
        carry_object("/d/longzhu/weapon/spear")->wield();
} 

void init () 
{       
        object *t; 
        object me=this_object(); 
        object who=this_player(); 
        int t1; 
        
        
        if(!environment(me)->query("magicroom")) 
        {call_out("destructing",1);} 
        t1=query("stay_time"); 
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
        ::kill_ob(ob); 
}

/*
void checking (object me, object ob)
{
        object *t;
        int damage;
        
        damage = ob->query_temp("apply/damage");
        
        if (me->is_fighting()){
                remove_call_out ("checking");  
                call_out ("checking",1,me,ob);  
        }
        else if( pointerp(t = ob->query_team())){
                if(ob->query_temp("teampower")){ 
                        ob->add_temp("apply/damage",-damage*20/100);   
                        ob->delete_temp("teampower");                                                                                                                                                                                                                                                                                                                  
                }                
        }
        else{           
                if(ob->query_temp("noteam")){   
                        ob->add_temp("apply/damage",damage*20/100); 
                        ob->delete_temp("noteam");
                }                                                                                                                                                                    
        }                
}
*/

void reward()  
{ 
        object killer,newob; 
        int exp_reward,pot_reward,dx_reward,gold_reward,i,j;
        
        killer = this_object()->query_temp("last_damage_from"); 
        exp_reward = random(7000)+9000;
        dx_reward = random(7000)+9000;
        pot_reward = exp_reward/5;
        gold_reward = random(2000000)+3000000;
        j = sizeof(killer->query_team());

        if(random(100)>90){
                if(random(2)){  
                        for(i=0;i<random(4);i++){             
                                newob = new("/d/quest/zhuangbei/weapon/"+list2[random(sizeof(list2))]);                                                        
                                newob->move(environment(killer));       
                        }         
                }             
                else {
                        for(i=0;i<random(4);i++){   
                                newob = new("/d/quest/zhuangbei/armor/"+list4[random(sizeof(list4))]);             
                                newob->move(environment(killer));    
                        }                                           
                }  
        }
        else if(random(100)>85){
                if(random(2)){  
                        for(i=0;i<random(4);i++){             
                                newob = new("/d/quest/zhuangbei/weapon/yweapon/"+list1[random(sizeof(list1))]);                                                        
                                newob->move(environment(killer));       
                        }         
                }             
                else {
                        for(i=0;i<random(4);i++){   
                                newob = new("/d/quest/zhuangbei/armor/yarmor/"+list3[random(sizeof(list3))]);             
                                newob->move(environment(killer));    
                        }                                           
                }  
        }      
        if(random(100)>20){
                if( j>=2 ){
                        if (killer->is_team_leader()) {
                                killer->add("combat_exp",exp_reward/2);
                                killer->add("potential",pot_reward/2);
                                killer->add("daoxing",dx_reward/2);
                                tell_object(killer,HIY"��õ���"+COMBAT_D->chinese_daoxing(dx_reward/2)+"���к�"+exp_reward/2+"����ѧ�����Լ�"+pot_reward/2+"��Ǳ�ܵĽ�����\n" NOR); 
                        }
                        else {
                                killer->add("combat_exp",exp_reward/2*(j-1));
                                killer->add("potential",pot_reward/2*(j-1));
                                killer->add("daoxing",dx_reward/2*(j-1));
                                tell_object(killer,HIY"��õ���"+COMBAT_D->chinese_daoxing(dx_reward/2*(j-1))+"���к�"+exp_reward/2*(j-1)+"����ѧ�����Լ�"+pot_reward/2*(j-1)+"��Ǳ�ܵĽ�����\n" NOR); 
                        }
                }
                else if(!pointerp(killer->query_team())){
                        killer->add("combat_exp",exp_reward);
                        killer->add("potential",pot_reward);
                        killer->add("daoxing",dx_reward);
                        tell_object(killer,HIY"��õ���"+COMBAT_D->chinese_daoxing(dx_reward)+"���к�"+exp_reward+"����ѧ�����Լ�"+pot_reward+"��Ǳ�ܵĽ�����\n" NOR); 
                }
        } 
        if(random(100)>95){
                if( j>=2 ){
                        if (killer->is_team_leader()) {
                                killer->add("balance",gold_reward/2);
                                tell_object(killer,HIY"��õ���"+MONEY_D->money_str(gold_reward/2)+"�Ľ�����\n" NOR); 
                        }
                        else {
                                killer->add("balance",gold_reward/2*(j-1));
                                tell_object(killer,HIY"��õ���"+MONEY_D->money_str(gold_reward/2*(j-1))+"�Ľ�����\n" NOR); 
                        }
                }
                else if(!pointerp(killer->query_team())){
                        killer->add("balance",gold_reward);
                        tell_object(killer,HIY"����ս�����ã��㻹�õ���"+MONEY_D->money_str(gold_reward)+"�Ľ�����\n" NOR); 
                }
        }               
}  
