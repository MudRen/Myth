// laoshu.c ����
// created by kuku@sjsh 2002/12

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("����", ({"laoshu jing","laoshu", "shu"}));
    set_weight(1000000);
  set("gender", "����" );
  set("age", 100);
  set("long", "һֻ��ë��������Ȼ�Ѿ��ϵĳɾ��ˡ�\n");
  set("combat_exp", 7500000);
  set("attitude", "heroic");
  set("daoxing", 7500000);
    create_family("�ݿ�ɽ�޵׶�", 3, "С��");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set("str",40);
  set_skill("unarmed", 350);
  set_skill("dodge", 380);
  set_skill("parry", 360);
  set_skill("spells", 360); 
  set_skill("yaofa", 360);
  set_skill("sword",390);
  set_skill("qixiu-jian",390);
  set_skill("blade", 380);
    set_skill("kugu-blade", 380);
  set_skill("lingfu-steps", 350);
  set_skill("yinfeng-zhua", 350);
  set_skill("force", 380);   
  set_skill("huntian-qigong", 380);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
  set("per", 20);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("force", 3800);
  set("max_force", 2000);
  set("force_factor", 150);
  set("mana",3000);
  set("max_mana", 3000);
  set("mana_factor", 50);
  set("chat_chance_combat", 65);
   set("chat_msg_combat", ({
     (: exert_function, "zhangqi" :),
        (: perform_action,"blade", "pozhan" :),
        (: perform_action,"blade", "diyu" :),
   }) );
  setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/obj/cloth/pobuyi")->wear();
}

void kill_ob (object ob) 
{ 
          set_temp("my_killer",ob);   
          ::kill_ob(ob);   
} 

void die()
{
        object corpse;
           object ob = query_temp("my_killer"); 
           if (environment()){
           if ( ob->query("wine/start") && present("jiu pai",ob))
           ob->set_temp("killshu",1);}
           if( objectp(corpse = CHAR_D->make_corpse(this_object(), ob)) )  
               corpse->move(environment(ob));  
          message_vision("$N���ˡ�\n",this_object());  
             destruct(this_object());  
}

void unconcious()
{
  die ();
}
