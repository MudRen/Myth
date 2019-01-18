
#include <ansi.h>
inherit NPC;
#include "robber.h"

void create()
{ 
        set_name("�ɼҰ���",({"xianjia bailei", "bailei", }));
        set("long","�Ըʶ��䣬Ͷ��ħ���һλ��ͽ��\n");
        set("gender", "Ů��" );
        set("family/family_name", "�¹�");
        set("age", random(50)+155);        
        set("vendetta/authority", 1);
        set("attitude", "peaceful"); 
        set("bellicosity", 1000);
        set("max_kee", 4000);
        set("kee", 4000);
        set("max_sen", 4000);
        set("sen", 4000);
        set("force", 7500);
        set("max_force", 4000);
        set("force_factor", 250);
        set("mana_factor", 250);
        set("shen_type", -10);
        set("combat_exp", 15000000);
        set("daoxing", 15000000);

        set_skill("force", 380); 
        set_skill("unarmed", 380);
        set_skill("dodge", 380);
        set_skill("parry", 380);
        set("chat_chance_combat", 120);  
        set("chat_msg_combat", ({
                (: perform_action, "whip", "huabian" :),
                (: perform_action, "whip", "jueqing" :),
                (: cast_spell, "mihun" :), 
                (: cast_spell, "arrow" :), 
                (: cast_spell, "shiyue" :), 
        }) );

        setup();
        carry_object("d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/obj/cloth/xianyi")->wear();
        carry_object("/d/obj/armor/jinjia")->wear(); 

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

        me->set_skill("whip", temp+60+random(50));
        me->set_skill("unarmed",temp+60+random(50));
        me->set_skill("force",temp+60+random(50));
        me->set_skill("dodge", temp+60+random(50));
        me->set_skill("spells", temp+60+random(50));
        me->set_skill("parry", temp+60+random(50));
        me->set_skill("jueqingbian", temp+60+random(50));
        me->set_skill("baihua-zhang", temp+60+random(50));
        me->set_skill("moonforce", temp+60+random(50));
        me->set_skill("moondance", temp+60+random(50));
        me->set_skill("moonshentong", temp+60+random(50));

        me->map_skill("whip","jueqingbian");
        me->map_skill("parry","jueqingbian");
        me->map_skill("unarmed","baihua-zhang");
        me->map_skill("force","moonforce");
        me->map_skill("spells","moonshentong");
        me->map_skill("dodge","moondance");

        me->set_temp("apply/damage", 150);
        me->set_temp("apply/attack", 150);
        me->set_temp("apply/defense", 150);
        me->set_temp("apply/armor", 150);
        if (random(20)>15)
        {
                me->set_temp("apply/attack", 200);
                me->set_temp("apply/defense", 300);
                me->set_temp("apply/armor", 300);
                me->set_temp("apply/damage", 200);
        }


        me->set("kee",(ob->query("max_kee")*3));        
        me->set("eff_kee",(ob->query("max_kee")*3));
        me->set("max_kee",(ob->query("max_kee")*3));
        me->set("max_sen",(ob->query("max_sen")*3));
        me->set("eff_sen",(ob->query("max_sen")*3));        
        me->set("sen",(ob->query("max_sen")*3));
        me->set("max_force",(ob->query("max_force")*3));
        me->set("force",(ob->query("max_force")*3));
        me->set("max_mana",(ob->query("max_mana")*3));
        me->set("mana",(ob->query("max_mana")*3));

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]+10+random(10));
        me->set("int", hp_status["int"]+10+random(10));
        me->set("con", hp_status["con"]+10+random(10));
        me->set("dex", hp_status["dex"]+10+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*3);
        me->set("daoxing",hp_status["daoxing"]*3);
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


