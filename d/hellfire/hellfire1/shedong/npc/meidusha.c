// Created By stey

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

void random_pfm();
void do_pfm(object me);



void setskill()
{
    int i;
        string *kk,*type;
        type=({"ħ��ʦ" ,"�ս���" ,"���ڵ���ʹ��",});


        kk=keys(hellskill);
        for(i=0;i<sizeof(kk);i++)
        {
                set("hell_skill/"+kk[i],hellskill[kk[i]] * 5 );
        }
        set("hell_exp",1000000);
        set("level",300+random(300));
        set("hell_type",type[random(sizeof(type))]);
}

void create(int level,int value)
{

    set_name("����ɯ",({"meidusha",}));

    if(!value) value=random(50)+50;
    if(!level) level=random(50)+50;




    set("age", 100+random(80));
    set("gender", "Ů��");
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
    set("combat_exp",value*300000);
    set("daoxing",value*300000);
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
    set_temp("apply/damage", level*10);

    set("no_steal",1);
    set("taskguai",1);
    setskill();

            set("chat_chance", 4);
            set("chat_msg", ({
                 (: random_pfm :)
            }) );

    set("inquiry", ([

      ]) );
    setup();
    carry_object("/d/obj/new-weapon/spear")->wield();
    carry_object("/d/obj/armor/tongjia")->wear();
    carry_object("/d/obj/new-weapon/"+w_type[random(sizeof(w_type))]);

      if(random(40)==2)
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
    add_action("block_cmd","",1);
    ::init();


}
int block_cmd()
{
        string verb = query_verb();
        object me = this_player();

        // wizard set hellfire allow all.
        if (wizardp(me) && me->query("env/hellfire"))
                 return 0;
        // ���߿�allow all
        if (!me->query_temp("hell_died"))
                 return 0;

        if (verb=="tell") return 0;
        if (verb=="chat") return 0; //allow chat
        if (verb=="help") return 0;
        if (verb=="look") return 0;
        if (me->query_temp("shixiang")) return 1;
        if (verb=="quit") {
                this_player()->delete_temp("hell_died");
                this_player()->delete("env/invisibility");
                this_player()->move("/d/city/kezhan");
                }
        return 1;
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





    ::heart_beat();
}

void kill_ob (object ob)
{
    object me = this_object();

    ::kill_ob(ob);
}
void random_pfm()
{
            object *killer,ob;
        int i,reward,exp;

   ob=this_object();
   killer=all_inventory(environment(ob));

   for(i=0;i < sizeof(killer);i++)
   {
        reward=0;
    if (!objectp(killer[i]) || !living(killer[i])) continue;
    if (userp(killer[i]))
    {
     do_pfm(killer[i]);
    }
   }

}

void do_pfm(object me)
{
    object ob;
        int damage;

    ob=this_object();
    if(!me) return;


    if(me->query("kee")<10 || me->query("sen")<10 ) return ;

    damage=ob->query("max_sen")/30;
    switch(random(2))
    {
    case 0:
            message_vision(YEL"$N����һ��Ѫ��ɫ�Ĺ�����$N��������Ѫ����������Ѫ����$n������\n",ob,me);


            if(random(100+me->query("hell_skil/dodge")) > me->query("hell_skil/dodge"))
            {

                message_vision(HIM"$N��Ѫ����������,�ܵ������˺���\n"NOR,me);
                me->receive_wound("kee",damage,ob);
                me->receive_damage("sen",damage,ob);
                me->receive_wound("sen",damage,ob);
            }
            else
                message_vision(YEL"$N��æ����һ������ʱ������Ѫ����\n"NOR,me);
        break;
    case 1:

            if(random(4)==0)
            {
               message_vision(YEL"$N���з���һ���ر�Ĺ�â��$n��ʱ��֪���죡\n",ob,me);
            if(me->query_temp("apply/meidusha")>1)
               {
                message_vision(YEL"$N����ħ�����˹�â���䣬����������â����ʱ���˸�������\n"NOR,me);
                return ;
               }
                message_vision(HIR"$N�Ķ�ʱ�е����ֽŽű������â�����ˣ�$N����˸�ʯ��\n"NOR,me);
                me->set_temp("apply/name",({me->name()+"ʯ��"}));
                me->set_temp("apply/id",me->parse_command_id_list());
                me->set_temp("apply/short", ({"ʯ��\n"+me->short()}));
                me->set_temp("apply/long", ({"ʯ��\n"+me->long()}));
                me->set_temp("shixiang",1);


                me->receive_damage("kee",damage/6,ob);
                me->receive_wound("kee",damage/6,ob);
                me->receive_damage("sen",damage/6,ob);
                me->receive_wound("sen",damage/6,ob);
            }

            break;
    }



}

void die()
{
        object *killer;
        string msg;
        int i;
        this_object()->add_temp("die_times",1);
         if( query_temp("die_times")< 7 )
    {
        set("eff_kee", query("max_kee"));
        set("eff_sen", query("max_sen"));
        set("kee", query("max_kee"));
        set("sen", query("max_sen"));
        set("force", query("max_force"));
        set("mana", query("max_mana"));
    }else
    {
        killer=all_inventory(environment(this_object()));
        msg="\n\n           ��¡һ�����죡��е����ڶ�ɽ��ҡ��\n\n";
        for(i=0;i < sizeof(killer);i++)
        {

        if(!userp(killer[i])) continue;
        if (killer[i]->query_temp("shixiang"))
        {
        killer[i]->delete_temp("shixiang");
        killer[i]->delete_temp("apply/name");
        killer[i]->delete_temp("apply/id");
        killer[i]->delete_temp("apply/short");
        killer[i]->delete_temp("apply/long");
        }
        msg +=killer[i]->name()+"("+killer[i]->query("id")+")��";
        }
        environment(this_object())->set("exits/enter","/d/hellfire/hellfire2/in");
        environment(this_object())->set("open_time",time());
        msg+="����ԡѪ��սɱ��������ɯ�����˵���֮��ڶ��㣡\n\n";
       
        message("system",HIG+ msg +NOR,users()); 

        ::die();
    }
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
                 ob->add("damage_rekee/"+who->query("id"),damage*2);
                 ob->add("total_rekee",damage*2);
                 break;
                case "sen":
                 ob->add("damage_rekee/"+who->query("id"),damage*2);
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
   if(killer[i]->query("hell_pot")>1200000) continue;
        if(ob->query("damage_rekee/"+killer[i]->query("id"))>0)
        {
        reward=ob->query("damage_rekee/"+killer[i]->query("id"));

        reward =(reward*100)/(ob->query("total_rekee"));

        if(reward>10)
        {
                exp=((ob->query("level"))*reward)/20;
                exp=random(exp)+1;

        killer[i]->add("magic_pointed",(random(exp)+1)/5);
        killer[i]->add("hell_exp",exp);
        killer[i]->add("hell_pot",exp/2);
        tell_object(killer[i],HIR"��ȵ����ɵ�ħ�����"+exp+"����������"+exp/5+"�㼼�������㡣\n"NOR);

        }
        }

    }
   }
}



