// by snowcat

inherit NPC;

void create()
{
  set_name("����", ({"shi nv","shinv","nv"}));
  set("gender", "Ů��");
  set("combat_exp", 10000);
  set("age", 15);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);

  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
}


