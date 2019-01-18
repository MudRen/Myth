// Created By stey

inherit NPC;

#include <ansi.h>


#define MOFENGD  "/d/quest/mofeng/mofengd"
void set_skills(int max_value, int level);
mapping hellskill=([
   "sword":100,"blade":100,"hammer":100,"staff":100,"whip":100,
   "axe":100,  "fork":100,"spear":100,"mace":100,"stick":100,"unarmed":100,"dodge":100,
]);
string *w_type=({
     "sword","spear","axe","hammer","stick","blade","staff","whip","mace","fork",
});
mapping color_list = ([
"��":   "chi",          "��":   "hong",
"��":   "huang",        "��":   "lu",
"��":   "qing",         "��":   "lan",
"��":   "zi",           "��":   "wu",
"��":   "hei",          "��":   "yin",
"��":   "bai",          "��":   "jin",
"��":   "hui",          "ľ":   "mu",
"ˮ":   "shui",         "��":   "huo",
"��":   "tu",           "θ":   "wei",
"��":   "gui",          "��":   "yue",
"��":   "zhu",          "��":   "ri",
"��":   "dou",          "��":   "zui",
 "��":   "kui",          "��":   "shen",
]);

mapping middle_list =([
"��"    :       "jiao",         "ͷ"    :       "tou",
"β"    :       "wei",          "��"    :       "zui",
"��"    :       "er",           "��"    :       "yan",
"��"    :       "bi",           "��"    :       "ya",
"��"    :       "she",          "��"    :       "shen",
"צ"    :       "zhua",
]);

mapping animal_list =([
"��":   "tu",           "��":   "hu",
"��":   "long",         "��":   "jiao",
"��":   "hu",           "��":   "bao",
"��":   "ma",           "¹":   "lu",
"��":   "yang",         "��":   "she",
"�":   "zhang",        "��":   "ji",
"��":   "gou",          "��":   "lang",
"Գ":   "yuan",         "��":   "hou",
"��":   "shu",          "ţ":   "niu",
"��":   "zhu",          "��":   "fu",
"��":   "chai",         "̡":   "lai",
"��":   "fei",          "��":   "mang",
"��":   "xiong",        "��":   "xiang",
"��":   "diao",         "��":   "li",
"�":   "huan",         "�":   "pi",
"��":   "yan",          "�":   "yin",
"��":   "zhi",          "��":   "pao",
"�":   "ni",           "��":   "ao",
"��":   "ling",         "��":   "ji",
"��":   "xing",         "ħ":   "mo",
"ѻ":   "ya",
]);

setname()
{
        mapping name;
        int a,b,c;
        string *surnames, *middle_names, *last_names;
        string temp_name, *temp_id, long;

        name=allocate_mapping(2);
       
                        surnames=keys(color_list);
                        middle_names=keys(middle_list);
                        last_names=keys(animal_list);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(last_names));
                        name=([
                                "name"  : surnames[a]+
                                          middle_names[b]+
                                          last_names[c],
                                "id"    : ({color_list[surnames[a]]+
                                            middle_list[middle_names[b]]+" "+
                                            animal_list[last_names[c]],
                                            animal_list[last_names[c]]}),
                        ]);
       
        set_name(name["name"],(name["id"]));

}





void create(int level,int value)
{
    
    setname();

    if(value==0) value=random(10)+15;
    if(level==0) level=random(10)+10;




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
    set("kee", value*100);
    set("max_kee", value*300);
    set("eff_kee", value*300);
    set("sen", value*200);
    set("max_sen", value*300);
    set("eff_sen", value*300);
    set("force", value*500);
    set("max_force", value*500);
    set("mana", value*500);
    set("max_mana", value*500);
    set("force_factor", value*50);
    set("mana_factor", value*50);
    set("level",value);
    set("combat_exp",value*2000000);
    set("daoxing",value*2000000);
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    

    set_temp("apply/armor", level*50);
    set_temp("apply/damage", level*10);

    set("no_steal",1);
    set("taskguai",1);
    set_skills(value*30,4);
   
    set("inquiry", ([

      ]) );
    setup();

      if(random(60)==2)
    carry_object("/d/quest/baoshi/baoshi");
}





void init ()
{   
    object me=this_object();
    object who=this_player();
    int t;
/*
    if(!environment(me)->query("mofengroom"))
    {call_out("destructing",1);}
*/

    t=query("stay_time");
    if(userp(who))
        kill_ob(who);
    ::init();


}
void destructing()
{
    destruct(this_object());
}

void set_skills(int max_value, int level)
{
    object guai=this_object();
    int guai_value;

    if (level==1) guai_value = max_value+max_value/5;
    else if (level==2) guai_value = max_value+max_value/4;
    else guai_value = max_value+max_value/3;

    set_skill("unarmed", guai_value+random(16));
    set_skill("dodge", guai_value+random(16));
    set_skill("parry", guai_value+random(16));
    set_skill("force", guai_value+random(16));
    set_skill("spells", guai_value+20+random(16));
}
void heart_beat()
{
    object guai = this_object();
    object me=this_object()->query_temp("last_damage_from");

    if ( !is_fighting()
      && query("eff_kee") >= query("max_kee") / 2
      && !query_skill("tonsillit",1)
      && !query_skill("shushan-force",1)

      && query("eff_kee") <  query("max_kee") )
    {

        set("eff_kee",query("max_kee"));
        set("eff_sen",query("max_sen"));

    }
    if (query("kee") < query("eff_kee")-10 )
    {
        command("exert recover");

    }
    if (query("sen") < query("eff_sen")-10)
        command("exert refresh");
    if( is_busy() && random(3)>1)
        start_busy(1);
    if (query("force") < query("max_force")/10)
        command("cast transfer");



    if (me && is_fighting(me) )
    {
        if ( random(5)==1) "/d/hellfire/npc/attack"->auto_attack(guai,me);
    }



    ::heart_beat();
}

void kill_ob (object ob)
{
    object me = this_object();

    ::kill_ob(ob);
}





varargs int receive_wound(string type, int damage, object who)
{
        object ob=this_object();


      if(!who) return ::receive_damage(type, damage, who);
        if(userp(who)) {

           // can't use other's NPC to help kill.
         if(damage>0) {
            switch(type) {
                case "kee":
                 ob->add("damage_rekee/"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                 break;
                case "sen":
                 ob->add("damage_rekee/"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break;
                        }
                      }
                       }

    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
     object ob=this_object();

       if (!who) return ::receive_damage(type, damage, who);
        if(userp(who)) {
           // can't use other's NPC to help kill.
        if(damage>0) {
            switch(type) {
                case "kee":
                 ob->add("damage_rekee/"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break;
                case "sen":
                 ob->add("damage_rekee/"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break;
                      }
                      }
                      }

    return ::receive_damage(type, damage, who);
}


void reward()
{

        object ob;
        int i,reward,type;
        string *list;
        mapping count;
       
        ob=this_object();
        
        type=(ob->query("level"))/5;
        
        if(!ob->query("total_rekee")) return;
        
        count=ob->query("damage_rekee");
        list=keys(count);
        
        for(i=0;i < sizeof(list);i++)
        {
           
            reward=0;
            reward=count[list[i]];
            reward =(reward*100)/(ob->query("total_rekee"));
            if(reward>10)  MOFENGD->record_damage(ob,list[i],reward,type);
        
        }
 
}


