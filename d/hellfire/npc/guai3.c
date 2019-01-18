// written By stey
#define ATTACKS  "/d/hellfire/npc/attack"
inherit NPC;

#include <ansi.h>
//#include "pfm.h"
mapping hellskill=([
   "sword":100,"blade":100,"hammer":100,"staff":100,"whip":100,
   "axe":100,  "fork":100,"spear":100,"mace":100,"stick":100,"unarmed":100,"dodge":100,
]);
string *w_type=({
     "sword","spear","axe","hammer","stick","blade","staff","whip","mace","fork",
});
mapping names1=([
 "��":"big",
 "С":"small",
 "˫":"two",
 "��":"odd",
 "��":"three",
 "��":"five",
 "��":"six",
 "��":"four",

]);

mapping names2=([
  "ͷ":"head",
  "β":"trail",
  "��":"feet",
  "צ":"claw",
  "��":"mouth",
  "��":"tooth",
]);
mapping names3=([

  "��"      :"monster",
  "��ʬ"    : "deadman",
  "����ʹ��" :"dark-mercury",
  "Ѫħ"    :"blood-demon",
  "����"    :"toxin-dragon",
  "����"    :"butcher",
  "ëͷ"    :"bad-kid",
  "����"    :"black-dragon",
  "����"    :" noxious-witch",
  "��Ѫ"    :  "xixue",
  "��Ȯ"    :  "dog",
  "����"    :  "bat",
  "���"    :  "hoptoad",
  "�ɻ�"    :  "locust",
  "�ȳ�"    :  "locust",
  "֩��"    :  "spider",
  "����"    :  "boa",
  "��֩��"  :  "spider",
  "Ѫ���"  :  "centipede",
  "��Ы��"  :  "scorpion",

]);

void setname1()
{
    int i,j,k;
    string name, *id,*nn,*mm,*pp;

     nn=keys(names1);
     mm=keys(names2);
     pp=keys(names3);

    i=random(sizeof(nn));
    j=random(sizeof(mm));
    k=random(sizeof(pp));

    name=nn[i]+mm[j]+pp[k];

    id=({names1[nn[i]]+" "+names2[mm[j]]+" "+
      names3[pp[k]], names3[pp[k]],"monsters",});

    set_name(name,id);

 set("magic_type",random(10)+5);


}


void setskill()
{
    int i;
        string *kk,*type;
        type=({"������" ,"ħ��ʦ" ,"�ս���" ,"������","���ڵ���ʹ��","Ұ����" ,});


        kk=keys(hellskill);
        for(i=0;i<sizeof(kk);i++)
        {
                set("hell_skill/"+kk[i],hellskill[kk[i]]*2 );
        }
        set("hell_exp",100000+random(100000));
        set("level",150+random(150));
        set("hell_type",type[random(sizeof(type))]);
}

void create(int level,int value)
{

    setname1();

    if(value==0) value=random(10)+15;
    if(level==0) level=random(10)+15;




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
    set("max_kee", value*100);
    set("eff_kee", value*100);
    set("sen", value*100);
    set("max_sen", value*100);
    set("eff_sen", value*100);
    set("force", value*400);
    set("max_force", value*400);
    set("mana", value*400);
    set("max_mana", value*400);
    set("force_factor", value*40);
    set("mana_factor", value*40);
    set("level",random(500)+1);
    set("combat_exp",value*100000);
    set("daoxing",value*70000);
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    set_skill("changquan", level*20);
    set_skill("yanxing-steps", level*20);
    set_skill("spear", level*20);
    set_skill("bawang-qiang", level*20);
    set_skill("lengquan-force", level*20);
    set_skill("literate", 180);
    set_skill("baguazhou", level*20);
    map_skill("spells", "baguazhou");
    map_skill("force", "lengquan-force");
    map_skill("unarmed", "changquan");
    map_skill("spear", "bawang-qiang");
    map_skill("parry", "bawang-qiang");
    map_skill("dodge", "yanxing-steps");

    set_temp("apply/armor", level*40);
    set_temp("apply/damage", level*6);

    set("no_steal",1);
    set("taskguai",1);
    setskill();
    /*
            set("chat_chance", 5);
            set("chat_msg", ({
            //     (: random_move :)
            }) );
    */
    set("inquiry", ([

      ]) );
    setup();
    carry_object("/d/obj/new-weapon/spear")->wield();
    carry_object("/d/obj/armor/tongjia")->wear();
    carry_object("/d/obj/new-weapon/"+w_type[random(sizeof(w_type))]);

      if(random(50)==2)
    carry_object("/d/quest/baoshi/baoshi");
}





void init ()
{   object ww,w;
    object me=this_object();
    object who=this_player();
    int t;
    if(!environment(me)->query("hellfireroom"))
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
        if ( random(5)==1) ATTACKS->auto_attack(guai,me);
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
                 ob->add("damage_rekee_"+who->query("id"),damage*2);
                 ob->add("total_rekee",damage*2);
                 break;
                case "sen":
                 ob->add("damage_rekee_"+who->query("id"),damage*2);
                 ob->add("total_rekee",damage*2);
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
                 ob->add("damage_rekee_"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break;
                case "sen":
                 ob->add("damage_rekee_"+who->query("id"),damage);
                 ob->add("total_rekee",damage);
                  break;
                      }
                      }
                      }

    return ::receive_damage(type, damage, who);
}


void reward()
{

        object *killer,ob;
        int i,reward,exp;

   ob=this_object();
   killer=all_inventory(environment(ob));

   for(i=0;i < sizeof(killer);i++)
   {
        reward=0;
    if (!objectp(killer[i])) continue; // mudring Nov/27/2002
    if (userp(killer[i]))
    {
   if(killer[i]->query("hell_pot")>500000) continue;
        if(ob->query("damage_rekee_"+killer[i]->query("id"))>0)
        {
        reward=ob->query("damage_rekee_"+killer[i]->query("id"));

        reward =(reward*100)/(ob->query("total_rekee"));

        if(reward>10)
        {
                exp=((ob->query("level"))*reward)/200;
                exp=random(exp)+1;

        killer[i]->add("magic_pointed",(random(reward)+1)/5);
        killer[i]->add("hell_exp",exp);
        killer[i]->add("hell_pot",exp/4);
//
        killer[i]->add("balance",5000);
        tell_object(killer[i],HIR"��ȵ����ɵ�ħ�����"+exp+"����������"+exp/5+"�㼼�������㡣\n"NOR);

        }
        }

    }
   }
}


