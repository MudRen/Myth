// created by kuku@sjsh
 
inherit NPC; 
#include <ansi.h>
void set_skills(int level);

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
        if(level==0) level=random(40)+10;  
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
        set("combat_exp",level*1500000); 
        set("daoxing",level*1500000); 
        set("food", 10000); 
        set("water", 10000); 
        set_weight(30000); 
        set("level",random(500)+1); 
        
        set_temp("apply/armor", level*40); 
        set_temp("apply/damage", level*10); 
        set_temp("apply/attack", level*10); 
        set_temp("apply/dodge", level*10); 
        set_temp("apply/spells", level*10); 
        set_temp("apply/armor_vs_force",level*20); 
        set_temp("apply/armor_vs_spells",level*20); 
        set("no_steal",1); 
        set("taskguai",1); 
        set("chat_chance", 5);
        setup(); 
} 

/*
void set_skills(int level) 
{
        object guai=this_object();       
        set_skill("unarmed", level*20); 
       set_skill("dodge", level*20); 
       set_skill("force", level*20); 
       set_skill("spells", level*20); 
       set_skill("parry", level*20); 
}       
*/

void init () 
{       object ww,w; 
        object me=this_object(); 
        object who=this_player(); 
        int t; 
        if(!environment(me)->query("magicroom")) 
        {call_out("destructing",1);} 
        t=query("stay_time"); 
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
        destruct(this_object());
}
