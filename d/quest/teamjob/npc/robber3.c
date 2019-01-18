
#include <ansi.h>
inherit NPC;
#include "robber.h"

void create()
{ 
        set_name("����ħ��",({"hunshi mowang", "mowang", }));
        set("long","������ħ�磬ȴ�������磬һ��Ҫ�����񾡰���\n");
        set("gender", "����" );
        set("family/family_name", "����ɽ���Ƕ�");
        set("age", random(50)+85);        
        set("vendetta/authority", 1);
        set("attitude", "peaceful"); 
        set("bellicosity", 1000);
        set("max_kee", 3000);
        set("kee", 3000);
        set("max_sen", 3000);
        set("sen", 3000);
        set("force", 6500);
        set("max_force", 3500);
        set("force_factor", 150);
        set("mana_factor", 150);
        set("shen_type", -10);
        set("combat_exp", 5000000);
        set("daoxing", 5000000);

        set_skill("force", 280); 
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({
                (: perform_action, "stick", "fantian" :),
                (: perform_action, "unarmed", "jingmo" :),
                (: perform_action, "stick", "qiankun" :),
                (: perform_action, "stick", "wu" :),
                (: cast_spell, "dingshen" :), 
                (: cast_spell, "light" :), 
                (: cast_spell, "thunder" :), 
        }) );

        setup();
        carry_object("d/obj/weapon/stick/wuchangbang")->wield();
        carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/armor/yinjia")->wear(); 

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

        me->set_skill("stick", temp+30+random(50));
        me->set_skill("unarmed",temp+30+random(50));
        me->set_skill("force",temp+30+random(50));
        me->set_skill("dodge", temp+30+random(50));
        me->set_skill("spells", temp+30+random(50));
        me->set_skill("parry", temp+30+random(50));
        me->set_skill("qianjun-bang", temp+30+random(50));
        me->set_skill("puti-zhi", temp+30+random(50));
        me->set_skill("wuxiangforce", temp+30+random(50));
        me->set_skill("jindouyun", temp+30+random(50));
        me->set_skill("dao", temp+30+random(50));

        me->map_skill("stick","qianjun-bang");
        me->map_skill("parry","qianjun-bang");
        me->map_skill("unarmed","puti-zhi");
        me->map_skill("force","wuxiangforce");
        me->map_skill("spells","dao");
        me->map_skill("dodge","jindouyun");

        me->set_temp("apply/damage", 150);
        if (random(20)>15)
        {
                me->set_temp("apply/attack", 200);
                me->set_temp("apply/defense", 200);
                me->set_temp("apply/armor", 200);
                me->set_temp("apply/damage", 200);
        }


        me->set("kee",(ob->query("max_kee")*2));        
        me->set("eff_kee",(ob->query("max_kee")*2));
        me->set("max_kee",(ob->query("max_kee")*2));
        me->set("max_sen",(ob->query("max_sen")*2));
        me->set("eff_sen",(ob->query("max_sen")*2));        
        me->set("sen",(ob->query("max_sen")*2));
        me->set("max_force",(ob->query("max_force")*2));
        me->set("force",(ob->query("max_force")*2));
        me->set("max_mana",(ob->query("max_mana")*2));
        me->set("mana",(ob->query("max_mana")*2));

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]+5+random(10));
        me->set("int", hp_status["int"]+5+random(10));
        me->set("con", hp_status["con"]+random(5));
        me->set("dex", hp_status["dex"]+5+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*5/2);
        me->set("daoxing",hp_status["daoxing"]*5/2);
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


