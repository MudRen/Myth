// robber1 for dart
//gemini����2000.4.4 ʹ�ø���ʱ���ο�literate�ȼ�
//by koker@sjsh 2002/04
#include <ansi.h>
inherit NPC;
#include "robber.h"
void create()
{ 
        set_name("�ٷ�",({"robbers"}));
        set("long","����һλ�޵׶����ӡ�\n");
        set("title","��·����");
        set("color", HIW );
        set("gender", "Ů��" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
        set("bellicosity", 100000);
        set("max_kee", 2000);
        set("eff_kee", 2000);
        set("kee", 900);
        set("max_sen", 900);
        set("sen", 500);
        set("force", 500);
        set("max_force", 500);
        set("jiali", 20);
        set("combat_exp", 500000);

        set_skill("force", 100); 
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
     
        setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player();       
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
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }

  set_skill("unarmed", temp);
  set_skill("dodge", temp);
  set_skill("parry", temp);
  set_skill("spells", temp); 
  set_skill("yaofa", temp);
  set_skill("sword",temp);
  set_skill("qixiu-jian",temp);
  set_skill("blade", temp);
  set_skill("kugu-blade", temp);
  set_skill("lingfu-steps", temp);
  set_skill("yinfeng-zhua", temp);
  set_skill("force", temp);   
  set_skill("huntian-qigong", temp);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
 



/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("daoxing", hp_status["daoxing"]+random(200000));
        me->set("combat_exp",hp_status["combat_exp"]);
        me->set("max_force", hp_status["max_force"]+random(500));
        me->set("force", hp_status["force"]+random(1000));
        me->set("max_mana", hp_status["max_mana"]+random(1000));
        me->set("mana", hp_status["mana"]+random(1000));
        me->set("max_kee", hp_status["max_kee"]);
        me->set("eff_kee", hp_status["max_kee"]);
        me->set("kee", hp_status["max_kee"]+random(1000));
        me->set("max_sen", hp_status["max_sen"]);
        me->set("eff_sen", hp_status["max_sen"]);
        me->set("sen", hp_status["sen"]+random(1000));
}
// passion add
void die()
{

        if( environment() ) {
        message("sound", 
"\n\nֻ��һ���ҽУ��ٷ˻���һ̲Ѫˮ\n\n", environment());        }
     destruct(this_object()); 

}

