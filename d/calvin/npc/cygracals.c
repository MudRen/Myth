inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
  set_name(HIW"����"NOR,({"NPC Cygracal"}));
  set("gender", "Ů��");
  set("title", HIR"�绢����"NOR);
  set("family/family_name", "��˿��");
  set("age", 18);
  set("long", HIC"    \n��������ʵΪ�绢�����ݺ�����֮�С�\n"NOR);

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
  set_skill("yinsuo-jinling",500); 
  set_skill("pansi-dafa", 500);
  set_skill("dodge", 500);
  set_skill("chixin-jian",500 );
  set_skill("force", 500);
  set_skill("qingxia-jian", 500);
  set_skill("sword", 500);
  set_skill("literate", 200);
  set_skill("parry", 500);
  set_skill("jiuyin-xinjing", 500);
  set_skill("spells", 500);
  set_skill("yueying-wubu", 500);
  set_skill("lanhua-shou", 500);
  set_skill("unarmed", 500);
  set_skill("whip",500);
map_skill("force", "jiuyin-xinjing");
map_skill("spells", "pansi-dafa");
map_skill("dodge", "yueying-wubu");
map_skill("whip", "yinsuo-jinling");
map_skill("parry", "yinsuo-jinling");
map_skill("unarmed", "lanhua-shou");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "whip", "feng" :),
                (: perform_action, "whip", "ding" :),
                (: perform_action, "whip", "wanling" :),
                (: perform_action, "whip", "wang" :),
                (: cast_spell, "zhui" :),
                (: cast_spell, "sishi" :),
               
        }) );


  set("nk_gain", 600);
   
  set_temp("apply/armor", 500);
  set_temp("apply/dodge", 500);
setup();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object("/d/calvin/npc/obj/waters.c")->wear();
carry_object("/d/pansi/obj/yinsuo.c")->wield();

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
