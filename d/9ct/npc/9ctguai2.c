// Created by kuku@sjsh 2003.5.17
 
inherit NPC; 
#include <ansi.h>

string *names1 = ({  
  "��","da",  
  "С","xiao",  
  "˫","shuang",  
  "��","dan",  
  "��","san",  
  "��","wu",  
  "��","liu",  
  "��","si",  
});  

string *names2 = ({  
  "ͷ","tou",  
  "β","wei",  
  "��","jiao",  
  "צ","zhua",  
  "��","zui",  
  "��","ya",  
});  

string *names3 = ({  
  "��","guai",  
  "��ʬ","deadman",  
  "ħ","mo",  
  "Ѫħ","xuemo",  
  "����","dragon",  
  "����","blackdragon", 
  "��","jing",
  "��","chong", 
});  

string *names4 = ({  
  "��Ѫ","xixue",  
  "��֩��","zhizhu",  
  "��Ȯ","equan",  
  "����","bianfu",  
  "��Ы��","xiezi",  
  "���","chanchu",  
  "Ѫ���","wugong",  
  "�ɻ�","feihuang",  
  "�ȳ�","huangchong",  
  "֩��","zhizhu",  
  "����","jumang",  
});  

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

void setname1()  
{  
    int i,j,k;  
    string name, *id;  

    i=(random(sizeof(names1)/2))*2;  
    j=(random(sizeof(names2)/2))*2;  
    k=(random(sizeof(names3)/2))*2;  

    name=names1[i]+names2[j]+names3[k];  
    id=({names1[i+1]+names2[j+1]+" "+  
      names3[k+1], names3[k+1],"tianshen"});  

    set_name(name,id);  
}  

void setname2()  
{  
    int i, j;  
    string name, *id;  
    i=(random(sizeof(names4)/2))*2;  
    j=random(2);  

    name=names4[i]+(j?"��":"����");  
    id=({names4[i+1]+" "+(j?"yao":"saintkiller"),  
      (j?"killer":"saintkiller"),"tianshen"});  

    set_name(name,id);  
}  
       
void create() 
{ 
        if(random(2)==0)  
                setname1();  
        else  
                setname2();  
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
        set("kee", 10000); 
        set("max_kee", 10000); 
        set("eff_kee", 10000); 
        set("sen", 10000); 
        set("max_sen", 10000); 
        set("eff_sen", 10000); 
        set("force", 6000); 
        set("max_force", 6000); 
        set("mana", 6000); 
        set("max_mana", 6000); 
        set("force_factor", 500);
        set("mana_factor", 500);
        set("level",random(500)+1);
        set("combat_exp", 10000000);
        set("daoxing", 10000000);
        set("food", 10000); 
        set("water", 10000); 
        set_weight(30000); 
        
        set_skill("dodge", 400);
        set_skill("unarmed", 400);
        set_skill("parry", 400);
        set_skill("moshenbu", 400);
        set_skill("force", 400);
        set_skill("wuxiangforce", 400);
        set_skill("sword", 400);
        set_skill("sanqing-jian", 400);
        set_skill("dao", 400);
        set_skill("spells", 400);
        map_skill("force", "wuxiangforce");
        map_skill("parry", "sanqing-jian");
        map_skill("sword", "sanqing-jian");
        map_skill("dodge", "moshenbu");
        map_skill("spells", "dao");
        
        set_temp("apply/armor", 800);
        set_temp("apply/dodge", 200);
        set_temp("apply/armor_vs_force",400); 
        set_temp("apply/armor_vs_spells",400); 
        create_family("����ɽ���Ƕ�",2 , "����");
        set("title",HIG"����"NOR);
        set("no_steal",1); 
        set("taskguai",1); 
        
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :),
                (: cast_spell, "dingshen" :)
        }));
        
        setup();
        carry_object("/d/9ct/zb/tianjia")->wear();
        carry_object("/d/9ct/zb/sword")->wield();
}
void init () 
{       
        object *t; 
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
        exp_reward = random(2000)+4000;
        dx_reward = random(2000)+4000;
        pot_reward = exp_reward/5;
        gold_reward = random(500000)+500000;
        j = sizeof(killer->query_team());

        if(random(100)>80){
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
        else if(random(100)>94){
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
        if(random(100)>40){
                if( j>=2 ){
                        if (killer->is_team_leader()) {
                                killer->add("combat_exp",exp_reward/2);
                                killer->add("potential",pot_reward/2);
                                killer->add("daoxing",dx_reward/2);
                                tell_object(killer,HIG"��õ���"+COMBAT_D->chinese_daoxing(dx_reward/2)+"���к�"+exp_reward/2+"����ѧ�����Լ�"+pot_reward/2+"��Ǳ�ܵĽ�����\n" NOR); 
                        }
                        else {
                                killer->add("combat_exp",exp_reward/2*(j-1));
                                killer->add("potential",pot_reward/2*(j-1));
                                killer->add("daoxing",dx_reward/2*(j-1));
                                tell_object(killer,HIG"��õ���"+COMBAT_D->chinese_daoxing(dx_reward/2*(j-1))+"���к�"+exp_reward/2*(j-1)+"����ѧ�����Լ�"+pot_reward/2*(j-1)+"��Ǳ�ܵĽ�����\n" NOR); 
                        }
                }
                else if(!pointerp(killer->query_team())){
                        killer->add("combat_exp",exp_reward);
                        killer->add("potential",pot_reward);
                        killer->add("daoxing",dx_reward);
                        tell_object(killer,HIG"��õ���"+COMBAT_D->chinese_daoxing(dx_reward)+"���к�"+exp_reward+"����ѧ�����Լ�"+pot_reward+"��Ǳ�ܵĽ�����\n" NOR); 
                }
        } 
        if(random(100)>90){
                if( j>=2 ){
                        if (killer->is_team_leader()) {
                                killer->add("balance",gold_reward/2);
                                tell_object(killer,HIG"��õ���"+MONEY_D->money_str(gold_reward/2)+"�Ľ�����\n" NOR); 
                        }
                        else {
                                killer->add("balance",gold_reward/2*(j-1));
                                tell_object(killer,HIG"��õ���"+MONEY_D->money_str(gold_reward/2*(j-1))+"�Ľ�����\n" NOR); 
                        }
                }
                else if(!pointerp(killer->query_team())){
                        killer->add("balance",gold_reward);
                        tell_object(killer,HIG"����ս�����ã��㻹�õ���"+MONEY_D->money_str(gold_reward)+"�Ľ�����\n" NOR); 
                }
        }               
}  
