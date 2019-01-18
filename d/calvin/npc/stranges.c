inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
  set_name(HIW"ܲܰ"NOR,({"NPC Strange"}));
  set("gender", "Ů��");
  set("title", HIR"���Ķ���"NOR);
  set("family/family_name", "����ɽ");
  set("age", 18);
  set("long", HIC"    \n���Ķ��ŵ�Ů������ͤͤ��������̬��\n"NOR);

  set("attitude", "heroism");
  set("class", "sanjie");
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

  set_skill("tianmogong", 500);
  set_skill("dodge", 500);
  set_skill("huxiaojian",500 );
  set_skill("force", 500);
  set_skill("zileidao", 500);
  set_skill("sword", 500);
  set_skill("literate", 200);
  set_skill("parry", 500);
  set_skill("huntianforce", 500);
  set_skill("spells", 500);
  set_skill("zhaoyangbu", 500);
  set_skill("huxiaoquan", 500);
  set_skill("unarmed", 500);
  set_skill("blade",500);
map_skill("force", "huntianforce");
map_skill("spells", "tianmogong");
map_skill("dodge", "zhaoyangbu");
map_skill("sword", "huxiaojian");
map_skill("parry", "huxiaojian");
map_skill("unarmed", "huxiaoquan");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "leihua" :),
                (: perform_action, "sword", "dunnotruth" :),
                (: perform_action, "sword", "dunnoname" :),
                (: perform_action, "sword", "chan" :),
                (: cast_spell, "zhui" :),
                (: cast_spell, "sishi" :),
               
        }) );


  set("nk_gain", 600);
   
  set_temp("apply/armor", 500);
  set_temp("apply/dodge", 500);
setup();
carry_object("/d/calvin/npc/obj/wea.c")->wear();
carry_object("/d/calvin/npc/obj/sea.c")->wear();
carry_object("/d/calvin/npc/obj/swords.c")->wield();

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
