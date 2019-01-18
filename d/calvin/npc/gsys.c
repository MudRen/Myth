inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
  set_name(HIW"�ü�"NOR,({"NPC Gsy"}));
  set("gender", "Ů��");
  set("title", HIR"����ǧ��"NOR);
  set("family/family_name", "��ׯ��");
  set("age", 18);
  set("long", HIC"    \n����ǧ��֮���ڴ�����\n"NOR);

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
  set("per", 40);

  set("int", 30+random(5));
  set("nkgain",790);

  set_skill("taiyi", 500);
  set_skill("dodge", 500);
  set_skill("xiaofeng-sword",500 );
  set_skill("force", 500);
  set_skill("sanqing-jian", 500);
  set_skill("sword", 500);
  set_skill("literate", 200);
  set_skill("parry", 500);
  set_skill("zhenyuan-force", 500);
  set_skill("spells", 500);
  set_skill("sevensteps", 500);
  set_skill("wuxing-quan", 500);
  set_skill("unarmed", 500);

map_skill("force", "zhenyuan-force");
map_skill("spells", "taiyi");
map_skill("dodge", "sevensteps");
map_skill("sword", "xiaofeng-sword");
map_skill("parry", "xiaofeng-sword");
map_skill("unarmed", "wuxing-quan");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "xiaofeng" :),
                (: perform_action, "sword", "xiaofeng" :),
                (: cast_spell, "zhenhuo" :),
                (: cast_spell, "qiankun" :),
               
        }) );


  set("nk_gain", 600);
   
  set_temp("apply/armor", 500);
  set_temp("apply/dodge", 500);
setup();
carry_object("/d/calvin/npc/obj/zhitao.c")->wear();
carry_object("/d/calvin/npc/obj/qilin.c")->wear();
carry_object("/d/obj/stey/sttt.c")->wield();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1;
  string weapon_id="stick";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","����޼�");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","������");
}
