inherit NPC;
#include <ansi.h>

inherit F_MASTER;
void create()
{
  set_name(HIW"����"NOR,({"NPC Mya"}));
  set("gender", "����");
  set("title", HIR"��������"NOR);
  set("family/family_name", "�ݿ�ɽ�޵׶�");
  set("age", 18);
  set("long", HIC"    \n��������֮���ڴ�������������Զ���̡�\n"NOR);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 100000000);
  set("daoxing", 10000000);
  set("kee", 100000);
  set("max_kee", 100000);
  set("sen", 100000);
  set("max_sen", 100000);
  set("force", 12000);
  set("max_force", 12000);
  set("mana", 10000);
  set("max_mana", 10000);
  set("force_factor", 500);
  set("mana_factor", 500);
  set("str", 50);
  set("int", 30+random(5));
  set("nkgain",790);
  set("per", 40);


  set_skill("dao", 500);
  set_skill("yaofa", 500);
  set_skill("dodge", 500);
  set_skill("kugu-blade",500 );
  set_skill("force", 500);
  set_skill("kugu-blade", 500);
  set_skill("blade", 500);
  set_skill("sword", 500);
  set_skill("qixiu-jian", 500);
  set_skill("literate", 200);
  set_skill("parry", 500);
  set_skill("huntian-qigong", 500);
  set_skill("spells", 500);
  set_skill("lingfu-steps", 500);
  set_skill("unarmed", 500);

map_skill("force", "huntian-qigong");
map_skill("spells", "yaofa");
map_skill("dodge", "lingfu-steps");
map_skill("sword", "qixiu-jian");
map_skill("parry", "kugu-blade");
map_skill("blade", "kugu-blade");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "blade", "shendao" :),
                (: perform_action, "blade", "diyu" :),
                (: perform_action, "blade", "pozhan" :),
               
        }) );

  set("nk_gain", 600);
   
  set_temp("apply/armor", 500);
  set_temp("apply/dodge", 500);

setup();
carry_object("/d/calvin/npc/obj/ddd.c")->wear();
carry_object("/d/calvin/npc/obj/aaa.c")->wear();
carry_object("/d/obj/stey/guiblade.c")->wield();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1;
  string weapon_id="stick";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","�ɻ�");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","õ��");
}
