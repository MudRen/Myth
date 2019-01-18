
#include <ansi.h>
inherit NPC;
#include "robber.h"

void create()
{ 
        set_name("����С��",({"xiao yao", "xiaoyao", "yao" }));
        set("long","ħ��С����������΢������η�塣\n");
        set("gender", "����" );
        set("family/family_name", "���ƶ�");
        set("age", random(30)+24);        
        set("vendetta/authority", 1);
        set("attitude", "peaceful"); 
        set("bellicosity", 1000);
        set("max_kee", 1000);
        set("kee", 1000);
        set("max_sen", 900);
        set("sen", 900);
        set("force", 2500);
        set("max_force", 1500);
        set("force_factor", 50);
        set("mana_factor", 50);
        set("shen_type", -10);
        set("combat_exp", 200000);
        set("daoxing", 200000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set("chat_chance_combat", 30);  
        set("chat_msg_combat", ({
                (: perform_action, "spear", "lihuo" :),
                (: perform_action, "spear", "ji" :),                
                (: perform_action, "unarmed", "zhangxinlei" :),                
        }) );

        setup();
        carry_object("d/obj/weapon/spear/gangqiang")->wield();
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        carry_object("/d/qujing/pingding/obj/armor")->wear(); 

}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      
      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
                        if(sname[i]=="force")i++;

                        if (i>0 && i <sizeof(skill_status))
                        {
                                if (skill_status[sname[i]] >= temp)
                                { temp = skill_status[sname[i]];}
                        }
                }
        } 
      else temp=(int)ob->query("force",1);

        me->set_skill("spear", temp+random(50));
        me->set_skill("unarmed",temp+random(50));
        me->set_skill("force",temp+random(50));
        me->set_skill("dodge", temp+random(50));
        me->set_skill("spells", temp+random(50));
        me->set_skill("parry", temp+random(50));
        me->set_skill("huoyun-qiang", temp+random(50));
        me->set_skill("moyun-shou", temp+random(50));
        me->set_skill("huomoforce", temp+random(50));
        me->set_skill("moshenbu", temp+random(50));
        me->set_skill("pingtian-dafa", temp+random(50));

        me->map_skill("spear","huoyun-qiang");
        me->map_skill("parry","huoyun-qiang");
        me->map_skill("unarmed","moyun-shou");
        me->map_skill("force","huomoforce");
        me->map_skill("spells","pingtian-dafa");
        me->map_skill("dodge","moshenbu");

        me->set("kee",(ob->query("max_kee")*3/2));      
        me->set("eff_kee",(ob->query("max_kee")*3/2));
        me->set("max_kee",(ob->query("max_kee")*3/2));
        me->set("max_sen",(ob->query("max_sen")*3/2));
        me->set("eff_sen",(ob->query("max_sen")*3/2));        
        me->set("sen",(ob->query("max_sen")*3/2));
        me->set("max_force",(ob->query("max_force")*3/2));
        me->set("force",(ob->query("max_force")*3/2));
        me->set("max_mana",(ob->query("max_mana")*3/2));
        me->set("mana",(ob->query("max_mana")*3/2));

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]+random(10));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(5));
        me->set("dex", hp_status["dex"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*3/2);
        me->set("daoxing",hp_status["daoxing"]*3/2);

        me->set("ygjg",ob);
}


void die()
{
        object ob;
        object robber;
        object room;
        ob=query_temp("last_damage_from");
        if (!ob) return;
        if (ob)
        {
                room = environment(ob);   
                if(ob->query_temp("start_job")==1)
                {
                        ob->add_temp("killed_mgb",1);
                }
                  else
                        ob->add_temp("help_killed",1);
                if( !ob->query_temp("job_over"))
                {
                        switch( random(3) ) {
                        case 0:
                        message_vision(WHT"������ɢ�����ֳ���һ��С����\n" NOR,ob); 
                        robber=new(__DIR__"robber1");
                        robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
                        ob->kill_ob(robber);
                        break;
                        case 1:
                        message_vision(WHT"������ɢ�����ֳ���һ���Ź�������\n" NOR,ob); 
                        robber=new(__DIR__"robber2");
                        robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
                        ob->kill_ob(robber);
                        break;
                        case 2:
                        message_vision(WHT"������ɢ�����ֳ���һ������ħ����\n" NOR,ob); 
                        robber=new(__DIR__"robber3");
                        
                        if( (int)ob->query("combat_exp",1)>5000000)
                        {
                                message_vision(HIY"����һ������Ϯ������Ȼ����һλ�ɼҰ��ࡣ\n" NOR,ob); 
                                robber=new(__DIR__"robber4");
                        }
                        robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
                        ob->kill_ob(robber);
                        break;
                        }       
                }
        }
              message_vision(WHT"$N���ڵ��������˼��£������������"HIR"��Ѫ"NOR"�����ˣ�\n",this_object());
                       destruct(this_object());
            return;
}


