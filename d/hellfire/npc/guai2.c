// Crack By stey  
  
inherit NPC;  
  
#include <ansi.h>  
//#include "pfm.h"  
  
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
  "����ʹ��","hellkiller",  
  "Ѫħ","xuemo",  
  "����","dragon",  
  "����","bakker",  
  "ëͷ","badkid",  
  "����","blackdragon",  
  "����","duwu"  
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
  
void setname1()  
{  
        int i,j,k;  
        string name, *id;  
  
        i=(random(sizeof(names1)/2))*2;  
        j=(random(sizeof(names2)/2))*2;  
        k=(random(sizeof(names3)/2))*2;  
  
        name=names1[i]+names2[j]+names3[k];  
        id=({names1[i+1]+names2[j+1]+" "+  
            names3[k+1], names3[k+1]});  
  
        set_name(name,id);  
  
  
  
        set("magic_tpye",0);  
}  
  
void setname2()  
{  
    int i, j;  
    string name, *id;  
    i=(random(sizeof(names4)/2))*2;  
    j=random(2);  
  
    name=names4[i]+(j?"ħ��":"����ʦ");  
    id=({names4[i+1]+" "+(j?"motou":"magickiller"),  
            (j?"killer":"magickiller")});  
  
    set_name(name,id);  
    set("magic_type",random(10)+5);  
}  
  
  
void create(int level,int value)  
{  
  
  
//void set_skills(int max_value, int level)  
  
          if(random(2)==0)  
            setname1();  
        else  
            setname2();  
  
        if(value==0) value=random(10)+10;  
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
        set("chat_chance", 5);  
        set("chat_msg", ({  
        //     (: random_move :)  
        }) );  
         set("inquiry", ([  
  
         ]) );   
        setup();   
        carry_object("/d/obj/weapon/spear/tiespear")->wield();  
        carry_object("/d/obj/armor/tongjia")->wear();  
         
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
 /* 
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
//   if (!owner() || owner()->query("rulaitask/fail") )  
//        destruct(guai);  
 
  
           if (is_fighting() )  
          {  
           if ( random(7)==1) call_out("check2",0);  
          }  
        

       ::heart_beat();  
}  
*/
  
void kill_ob (object ob)  
{  
          object me = this_object();  
  
              me->set_leader(ob);  
            ::kill_ob(ob);  
}  
  
  
void check2()  
{  
       object ob,me;  
        me=this_object()->query_temp("last_damage_from");  
            if(!me) return;
     if(! userp(me) && ! living(me) && is_fighting(me) && me=ob ) return ; 
 if(! present(me,environment()) )  
     {  
     remove_call_out("check2");  
     return;  
     }  
          if(me->query("combat_exp") <1000000 ) return ;  
         
        if(me->query("kee")<10 && me->query("sen")<10 ) return ;  
    
  
     switch(random(6))  
     {  
        case 0:  
        {  
        message_vision(YEL"$N���һ�����䣬��ħ��Ѫ������һ��Ѫ����$n������\n",ob,me);  
  
  
       if(random(6)==0)  
                {  

              message_vision(HIM"$N��Ѫ����������,�ܵ������˺���\n"NOR,me);  
              me->receive_wound("kee",query("max_sen")/55);  
              me->receive_damage("sen",query("max_kee")/55); 
              me->receive_wound("sen",query("max_sen")/55);  
                }  
        else  
        message_vision(YEL"$N��æ����һ������ʱ������Ѫ����\n"NOR,me);  
        }  
        break;  
  
  
        case 1:  
        {  
  
        message_vision(YEL"$N�����л��䣬��ʱ��ֻħ�����ſ������$n������\n",ob,me);  
  
                if(random(4)==0)  
  
                {  
              message_vision(HIR"$N�����ֽŽű�ħ���������ˣ��ܵ�����ֲ����˺���\n"NOR,me);  
              me->receive_damage("kee",2*query("max_kee")/55);  
              me->receive_wound("kee",2*query("max_sen")/55);  
              me->receive_damage("sen",2*query("max_kee")/55);  
              me->receive_wound("sen",2*query("max_sen")/55);  
                }  
                else  
                  message_vision(YEL"$N��������ǰһ�ӣ���ʱ���������ѣ�\n"NOR,me);  
        }  
        break;  
  
        case 2:  
        {  
  
        message_vision(HIR"$N����ͻȻ����һ��Ѫ��ɫ�Ļ��򣬻���������$n�ɹ�ȥ��\n",ob,me);  
  
//  
                if(random(40)>35)  
  
                {  
              message_vision(HIR"$N���Լ�ʱ��ܣ�����������Ļ��������ţ�\n"NOR,me);  
              me->receive_damage("kee",2*query("max_kee")/55);  
              me->receive_wound("kee",2*query("max_sen")/55);  
              me->receive_damage("sen",2*query("max_kee")/55);  
              me->receive_wound("sen",2*query("max_sen")/55);  
       
                }  
        else  
        message_vision(HIR"$N��ʱ��ָһ�����÷�����$n�Ļ��򲦿��ˣ�\n"NOR,me,ob);  
        }  
        break;  
  
  }  
        if( random(10) == 5 && ob->query("eff_kee")<ob->query("max_kee"))  
        {  
           set("eff_kee", query("max_kee"));  
           set("eff_sen", query("max_sen"));  
           set("kee", query("max_kee"));  
           set("sen", query("max_sen"));  
           set("force", query("max_force"));  
           set("mana", query("max_mana"));  
        }  
  
        remove_call_out("check2");  
  
}  
 
void reward()  
{ object killer; 
killer = this_object()->query_temp("last_damage_from"); 
        
 if (userp(killer)) 
          { 
                killer->add("magic_pointed",random(2)+1); 
           tell_object(killer,HIR"��ȵ����ɵ�ħ���㡣\n"NOR);  
        } 
  
}  
  
 
 

