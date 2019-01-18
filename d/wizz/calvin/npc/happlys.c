inherit NPC;
#include <ansi.h>

inherit F_MASTER;
void create()
{
  set_name(HIW"Ҷ��"NOR,({"NPC Happly"}));
  set("gender", "Ů��");
  set("title", HIR"��ͨ���"NOR);
  set("family/family_name", "�¹�");
  set("age", 18);
  set("long", HIC"    \n��������֮���ڴ�������������Զ���̡�\n"NOR);

  set("attitude", "heroism");
  set("class", "xian");
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


  set_skill("moonshentong", 500);
  set_skill("whip", 500);
  set_skill("dodge", 500);
  set_skill("xuanhu-blade",500 );
  set_skill("force", 500);
  set_skill("jueqingbian", 500);
  set_skill("blade", 500);
  set_skill("sword", 500);
  set_skill("snowsword", 500);
  set_skill("literate", 200);
  set_skill("parry", 500);
  set_skill("moonforce", 500);
  set_skill("spells", 500);
  set_skill("moondance", 500);
  set_skill("unarmed", 500);

map_skill("force", "moonforce");
map_skill("spells", "moonshentong");
map_skill("dodge", "moondance");
map_skill("sword", "snowsword");
map_skill("parry", "snowsword");
map_skill("blade", "xuanhu-blade");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "tian" :),
                (: perform_action, "sword", "hudie" :),
                (: perform_action, "sword", "huifeng" :),
                (: perform_action, "sword", "hanyue" :),
               
        }) );

  set("nk_gain", 600);
   
  set_temp("apply/armor", 500);
  set_temp("apply/dodge", 500);

setup();
carry_object("/d/calvin/npc/obj/slap.c")->wear();
carry_object("/d/calvin/npc/obj/nip.c")->wear();
        carry_object("/d/moon/obj/snow_sword.c")->wield();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1;
  string weapon_id="stick";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","��Сƽ����");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","ë����¼");
}
